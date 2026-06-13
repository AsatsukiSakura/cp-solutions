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
	int to;
	ll w;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	在给定的点中找出一个点使得到S最短路最长
	建反图跑一边djik
	*/
	int n,m,s;
	cin>>n>>m>>s;
	vector<vector<edge>>adj(n+1);
	for(int i=1;i<=m;i++){
		int u,v,ww;
		cin>>u>>v>>ww;
		adj[v].push_back({u,ww});
	}
	int k;
	cin>>k;
	vector<int>target(k+1);
	for(int i=1;i<=k;i++){
		cin>>target[i];
	}
	auto cmp=[](edge a,edge b){
		return a.w>b.w;
	};
	priority_queue<edge,vector<edge>,decltype(cmp)>pq(cmp);
	vector<bool>fi(n+1,0);
	vector<ll>dis(n+1,inf*inf);
	dis[s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		int u=pq.top().to;
		ll d=pq.top().w;
		pq.pop();
		if(!fi[u]){
			fi[u]=1;
			dis[u]=d;
			for(edge e:adj[u]){
				if(d+e.w<dis[e.to]){
					dis[e.to]=d+e.w;
					pq.push({e.to,d+e.w});
				}
			}
		}
	}
	ll ans=-1;
	for(int i=1;i<=k;i++){
		if(dis[target[i]]!=inf*inf)	
			ans=max(ans,dis[target[i]]);
	}
	cout<<ans;
	return 0;
}
