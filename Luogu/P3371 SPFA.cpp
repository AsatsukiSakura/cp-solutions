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
	int v,w;
	edge(int v,int w){
		(*this).v=v;
		(*this).w=w;
	}
};
bool spfa(int s,vector<vector<edge>> &g,vector<int> &d){
	queue<int>q;
	vector<bool>inq(g.size(),false);
	vector<int>cnt(g.size(),0);
	q.push(s);d[s]=0;inq[s]=true;
	while(!q.empty()){
		int u=q.front();
		inq[u]=false;
		q.pop();
		for(auto &[v,w]:g[u]){
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=g.size()-1)return false;
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
				}
			}
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,s;
	cin>>n>>m>>s;
	vector<vector<edge>>adj(n+1);
	vector<int>dis(n+1,inf);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(edge(v,w));
	}
	spfa(s,adj,dis);
	for(int i=1;i<=n;i++){
		cout<<(dis[i]==inf?INT_MAX:dis[i])<<' ';
	}
	return 0;
}
