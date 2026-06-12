#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-12;
/*
对每一段：E=k(v-v0)^2 s
v-v0=sqrt(E/ks);
T=s/(v0+sqrt(E/ks));
T'(E)<0 易得
对于不同段之间分配的E
所有段导数必相同
否则可以某段增加E,另一段减少E得到更小的sumT
T'(E)=-1/2kv^2(v-v0)
二分公共导数求解E即可
T=f(E)
*/
double solve(double c,double v0){
	double l=v0+eps;
	double r=1e8;
	while(r-l>eps){
		double mid=(l+r)/2;
		if (mid*mid*(mid-v0)>c)
			r=mid;
		else
			l=mid;
	}
	return (l+r)/2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	double et;
	cin>>n>>et;
	vector<double>s(n+1),k(n+1),v0(n+1);
	for(int i=1;i<=n;i++){
		cin>>s[i]>>k[i]>>v0[i];
	}
	double deriv;
	double l=eps,r=1e10;
	while(r-l>eps){
		double mid=(l+r)/2;
		double tott=0,tote=0;
		for(int i=1;i<=n;i++){
			double c=1.0/(2*k[i]*mid);
			double v=solve(c,v0[i]);
			double e=k[i]*(v-v0[i])*(v-v0[i])*s[i];
			tote+=e;
		}
		if(tote<et){
			r=mid;
		}
		else l=mid;
		deriv=(l+r)/2;
	}
	double tott=0;
	for(int i=1;i<=n;i++){
		double c=1.0/(2*k[i]*deriv);
		double v=solve(c,v0[i]);
		tott+=s[i]/v;
	}
	cout<<fixed<<setprecision(8)<<tott;
	return 0;
}
