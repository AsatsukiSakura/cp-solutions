#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
vector<int>disc,low,parent;
vector<vector<int>>adj;
vector<pair<int,int>>bridge;
int t;
void dfs(int u) {
	disc[u]=low[u]=++t;
	for(int v:adj[u]) {
		if(v==parent[u]) continue;
		if(disc[v]==0){
			parent[v]=u;
			dfs(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>disc[u]) {
				bridge.push_back({min(u,v),max(u,v)});
			}
		} else { 
			low[u] = min(low[u], disc[v]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,u,v;
	cin>>n>>m;
	disc.resize(n+1,0);low.resize(n+1,0);
	parent.resize(n+1,-1);adj.resize(n+1);
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!disc[i])
			dfs(i);
	}
	sort(bridge.begin(),bridge.end());
	for(auto p:bridge){
		cout<<p.first<<' '<<p.second<<endl;
	}
	return 0;
}
