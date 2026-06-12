#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
struct edge{
	int to,len;
	edge(int v,int w){
		to=v;len=w;
	}
};
vector<vector<edge>>adj;
bool operator>(edge a,edge b){
	return a.len>b.len;
}
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,s;
	cin>>n>>m>>s;
	adj.resize(n+1);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(edge(v,w));
	}
	vector<int>dis(n+1,inf);dis[s]=0;
	vector<bool>final_(n+1,false);final_[s]=true;
	priority_queue<edge,vector<edge>,greater<edge>>pq;
	for(edge e:adj[s]){
		dis[e.to]=e.len;
		pq.push(e);
	}
	while(!pq.empty()){
		int u=pq.top().to;
		pq.pop();
		if(final_[u])	continue;
		final_[u]=true;
		for(edge e:adj[u]){
			int v=e.to;
			if(!final_[v]&&dis[v]>dis[u]+e.len){
				dis[v]=dis[u]+e.len;
				pq.push(edge(v,dis[v]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<' ';
	}
	return 0;
}
