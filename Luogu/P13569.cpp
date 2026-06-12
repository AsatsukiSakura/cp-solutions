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
void solve(){
	
	double ppmax,a,b,c,d,e,f;
	double acc,pp;
	cin>>ppmax;
	cin>>a>>b>>c>>d>>e>>f;
	acc=(300*a+300*b+200*c+100*d+50*e)/(a+b+c+d+e+f)/3;
	pp=max((320*a+300*b+200*c+100*d+50*e)/(a+b+c+d+e+f)/64*ppmax-4*ppmax,0.0);
	cout<<fixed<<setprecision(2)<<acc<<"% "<<setprecision(0)<<pp<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
