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
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	vector<int>b(n+1);
	vector<int>g(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	vector<vector<int>>adj(n+1);
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	auto dfs=[&](auto &&self,int p,int u)->void{
		ll sum=0;
		ll ext=0;
		for(int v:adj[u]){
			if(v!=p){
				self(self,u,v);
				sum+=a[v];
				int gl=g[v]%b[v];
				ext=gcd(ext,gl);
			}
		}
		g[u]=gcd(b[u],gcd(sum,ext));
	};
	dfs(dfs,0,1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll jp=(b[i]-1-a[i])/g[i];
		ll mx=a[i]+jp*g[i]; 
		ans+=mx;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
