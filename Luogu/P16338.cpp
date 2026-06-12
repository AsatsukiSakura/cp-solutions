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
	int n,d;
	cin>>n>>d;
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	vector<vector<int>>tree(n+1);
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	auto dfs=[&](auto self,int p,int u)->pair<int,int>{
		int mx=a[u],sz=1;
		for(int v:tree[u]){
			if(v!=p){
				auto[subsz,submx]=self(self,u,v);
				sz+=subsz;
				mx=max(submx,mx);
			}		
		}
		return {sz,mx};
	};
	if(b[d]>2){cout<<"0\n";return;}
	int ans=0;
	for(int u:tree[d]){
		auto[sz,mx]=dfs(dfs,d,u);
		if(mx>=a[d])ans+=sz;
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
