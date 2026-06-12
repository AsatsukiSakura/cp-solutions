#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int n,m,s;
vector<int>dfn;
vector<vector<int>>adj;
vector<vector<int>>st;
int t=0;
void dfs(int p,int u){
	dfn[u]=++t;
	st[dfn[u]][0]=p;
	for(int v:adj[u]){
		if(v==p)continue;
		dfs(u,v);
	}
}
inline int dfnmin(int x,int y){
	if(dfn[x]<dfn[y])return x;
	else return y;
}
inline int lca(int u,int v){
	if(u==v)return u;
	if(dfn[u]>dfn[v])return lca(v,u);
	int p=log2(dfn[v]-dfn[u]-1);
	return dfnmin(st[dfn[u]+1][p],st[dfn[v]-(1<<p)+1][p]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>s;
	adj.resize(n+1);
	dfn.resize(n+1);
	st.resize(n+1,vector<int>(log2(n)+1));
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(s,s);
	for(int i=1;i<=log2(n);i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[j][i]=dfnmin(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		cout<<lca(u,v)<<'\n';
	}
	return 0;
}
