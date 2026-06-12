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
struct edge{
	int to,len;
	edge(int v,int w){
		to=v;len=w;		
	}
};
bool operator >(const edge &a,const edge &b){
	return a.len>b.len;
}
void djikstra(int s,vector<vector<edge>> &g,vector<int> &d){
	priority_queue<edge,vector<edge>,greater<edge>>pq;
	vector<bool>fin(d.size(),false);
	d[s]=0;
	pq.push(edge(s,d[s]));
	while(!pq.empty()){
		int u=pq.top().to;
		pq.pop();
		if(fin[u])continue;
		fin[u]=true;
		for(edge e:g[u]){
			if(!fin[e.to]&&d[e.to]>d[u]+e.len){
				d[e.to]=d[u]+e.len;
				pq.push(edge(e.to,d[e.to]));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<vector<edge>>adj(n+1),rev(n+1);
	vector<int>dis(n+1,inf),disr(n+1,inf);
	int ans=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(edge(v,w));
		rev[v].push_back(edge(u,w));
	}
	djikstra(1,adj,dis);
	djikstra(1,rev,disr);
	for(int i=2;i<=n;i++){
		ans+=(dis[i]+disr[i]);
	}
	cout<<ans;
	return 0;
}
