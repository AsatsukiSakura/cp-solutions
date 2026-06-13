#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=100003;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int>q;
	vector<int>dist(n+1,inf),cnt(n+1,0);
	q.push(1);dist[1]=0;cnt[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[u]){
			if(dist[v]>=dist[u]+1){
				if(dist[v]==inf)q.push(v);
				dist[v]=dist[u]+1;
				cnt[v]+=cnt[u];
				cnt[v]%=mod;
			}
		}	
	}
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<'\n';
	}
	return 0;
}