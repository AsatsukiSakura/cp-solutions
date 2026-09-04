#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=985661441;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1){
			r=r*b%mod;
		}
		b=b*b%mod;
		p>>=1;
	}
	return r;
}
vector<ll>fac(5001,1),ifac(5001,1);
ll C(int n,int k){
	if(k<0||k>n)return 0;
	return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>a(n+1);
	vector<vector<int>>s(n+1);
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	ifac[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		s[x].push_back(i);
	}
	vector<int>sz(n+1,0);
	vector<vector<array<ll,3>>>dp(n+1);
	auto dfs=[&](auto &&self,int u)->void{
		dp[u]={{1,0,0}};
		sz[u]=0;
		for(int v:s[u]){
			self(self,v);
			vector<array<ll,3>>ndp(sz[u]+sz[v]+2,{0,0,0});
			for(int i=0;i<=sz[u];i++){
				for(int j=0;j<=sz[v];j++){
					for(int ku=0;ku<=2;ku++){
						for(int kv=0;kv<=2;kv++){
							if(i+j<=n-1){
								ndp[i+j][ku]+=dp[u][i][ku]*dp[v][j][kv]%mod;
								ndp[i+j][ku]%=mod;
							}
							if(i+j+1<=n-1&&ku<=1&&kv<=1){								
								ndp[i+j+1][ku+1]+=dp[u][i][ku]*dp[v][j][kv]%mod;
								ndp[i+j+1][ku+1]%=mod;
							}
						}					
					}
				}
			}
			sz[u]+=sz[v]+1;
			dp[u]=ndp;
		}
	};
	dfs(dfs,1);
	ll ans=0;
	for(int i=3;i<=n-1;i++){
		ans+=1ll-(dp[1][i][0]+dp[1][i][1]+dp[1][i][2])%mod*qp(C(n-1,i),mod-2)%mod,
		ans=(ans+mod)%mod;
	}
	cout<<ans;
	return 0;
}
