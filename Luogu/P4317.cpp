#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=1e7+7;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin>>n;
	vector<vector<ll>>C(50,vector<ll>(50,0));
	for(int i=0;i<=49;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1]);
	}
	int cnt=0;
	vector<ll>p(50,0);
	for(int i=49;i>=0;i--){
		if((n>>i)&1){
			for(int j=0;j<=i;j++){
				debug(cnt+j);
				p[cnt+j]=p[cnt+j]+C[i][j];
			}
			cnt++;
		}
		if(i==0)p[cnt]++;
	}
	auto qp=[&](ll b,ll p){
		ll r=1;
		while(p){
			if(p&1)r=r*b%mod;
			b=b*b%mod;
			p>>=1;
		}
		return r;
	};
	ll ans=1;
	//debug(p[1]),debug(p[2]),debug(p[3]);
	for(int i=1;i<=49;i++)ans=ans*qp(i,p[i])%mod;
	cout<<ans<<'\n';
	return 0;
}
