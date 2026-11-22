#include<bits/stdc++.h>
using namespace std;
#define int long long
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
vector<ll>fact(1e6+1,1);
vector<ll>invfact(1e6+1);
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1)r=r*b%mod;
		b=b*b%mod;
		p>>=1;
	}
	return r;
}
void solve(){
	int n;
	cin>>n;
	vector<int>fa(n+1,0);
	for(int i=2;i<=n;i++)
		cin>>fa[i];
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	vector<vector<int>>adj(n+1);
	vector<int>in(n+1,0);
	for(int i=2;i<=n;i++){
		if(b[i]>a[fa[i]]||b[fa[i]]<a[i])
			adj[fa[i]].push_back(i),in[i]++;
	}
	vector<bool>vis(n+1,false);
	vector<ll>dp(n+1,1);
	vector<int>sz(n+1,0);
	auto dfs=[&](auto &&self,int p,int u)->void{
		vis[u]=true;
		sz[u]=1;
		for(int v:adj[u]){
			if(v==p)continue;
			self(self,u,v);
			sz[u]+=sz[v];
		}
	};
	ll ans=fact[n];
	for(int i=1;i<=n;i++){
		if(!vis[i]&&in[i]==0)dfs(dfs,0,i);
	}
	for(int i=1;i<=n;i++){
		ans=ans*qp(sz[i],mod-2)%mod;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=1;i<=1e6;i++)fact[i]=(1ll*i*fact[i-1])%mod;
	invfact[1e6]=qp(fact[1e6],mod-2);
	for(int i=999999;i>=0;i--)invfact[i]=1ll*(i+1)*invfact[i+1]%mod;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
