#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double a,b,c,d,e,f,g,x,y,z;
	cin>>a>>b>>c>>d>>e>>f>>g>>x>>y>>z;
	double p=g/(1.00-(a*d+b*e+c*f));
	double cx=x/(1.00-p);
	double cy=y/(1.00-p);
	double cz=z/(1.00-p);
	cout<<max({cx,cy,cz});
	return 0;
}
