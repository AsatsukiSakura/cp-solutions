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
struct edge{
	int v;
	int t;
	ll w;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,hh;
	cin>>n>>m>>hh;
	vector<vector<ll>>dis(hh+1,vector<ll>(n+1,inf*inf));
	vector<vector<bool>>fi(hh+1,vector<bool>(n+1,false));
	vector<vector<edge>>adj(n+1);
	auto cmp=[](edge a,edge b){
		return a.w>b.w;
	};
	priority_queue<edge,vector<edge>,decltype(cmp)>pq(cmp);
	vector<int>h(n+1),r(n+1);
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,114514,w});
		adj[v].push_back({u,114514,w});
	}
	pq.push({1,0,0});
	dis[0][1]=0;
	while(!pq.empty()){
		int u=pq.top().v;
		int t=pq.top().t;
		pq.pop();
		if(fi[t][u])continue;
		fi[t][u]=true;
		if(!fi[0][u]&&dis[0][u]>dis[t][u]+r[u]){
			dis[0][u]=dis[t][u]+r[u];
			pq.push({u,0,dis[0][u]});
		}
		for(edge e:adj[u]){
			if(h[e.v]<h[u]){
				if(!fi[0][e.v]&&dis[0][e.v]>dis[t][u]+e.w){
					dis[0][e.v]=dis[t][u]+e.w;
					pq.push({e.v,0,dis[0][e.v]});
				}
			}
			else{
				int d=h[e.v]-h[u];
				if(t+d<=hh&&!fi[t+d][e.v]&&dis[t+d][e.v]>dis[t][u]+e.w){
					dis[t+d][e.v]=dis[t][u]+e.w;
					pq.push({e.v,t+d,dis[t+d][e.v]});
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		ll ans=inf*inf;
		for(int j=0;j<=hh;j++){
			ans=min(ans,dis[j][i]);
		}
		cout<<(ans>=inf*inf?-1:ans)<<' ';
	}
	return 0;
}
