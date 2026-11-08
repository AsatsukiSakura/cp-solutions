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
	int a,b,c;
	cin>>a>>b>>c;
	vector<ll>fac(5001,1);
	for(int i=1;i<=5000;i++)
		fac[i]=fac[i-1]*i%mod;
	vector<vector<ll>>C(5001,vector<ll>(5001,0));
	for(int i=0;i<=5000;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	auto f=[&](int x,int y){
		ll tmp=0;
		for(int i=0;i<=min(x,y);i++){
			tmp=(tmp+C[x][i]*C[y][i]%mod*fac[i]%mod)%mod;
		}
		return tmp;
	};
	cout<<f(a,b)*f(a,c)%mod*f(b,c)%mod;
	return 0;
}
