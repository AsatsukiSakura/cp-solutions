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
bool dfs(int u,int c,vector<vector<int>>&adj,vector<int>&color,vector<bool>&vis,vector<int>&cpn){
	vis[u]=true;
	color[u]=c;
	cpn.push_back(u);
	bool bp=true;
	for(int v:adj[u]){
		if(!vis[v]){
			bp=dfs(v,1-c,adj,color,vis,cpn)&bp;
		}
		else if(color[u]==color[v])bp=false;
	}
	return bp;
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>color(n+1,-1);
	vector<bool>vis(n+1,0);
	vector<vector<int>>adj(n+1);
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vector<int>cpn;
			int c0=0,c1=0;
			bool b=dfs(i,0,adj,color,vis,cpn);
			if(b)for(int u:cpn){
				if(color[u]==0)c0++;
				else c1++;
			}
			cnt+=max(c0,c1);
		}
	}
	cout<<cnt<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
