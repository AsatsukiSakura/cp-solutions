#include<bits/stdc++.h>
using namespace std;
struct edge{
	int vertex,dis;
	edge(int v,int d){
		vertex=v;
		dis=d;
	}
};
bool operator<(edge x,edge y) {return x.dis>y.dis;}
priority_queue<edge>pq;
int main(){
	int n,m,x,y,z;
	cin>>n>>m;
	vector<bool>vis(n+1,false);
	vector<vector<edge>>adj(n+1);
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		adj[x].push_back(edge(y,z));
		adj[y].push_back(edge(x,z));
	}
	vis[1]=true;
	for(edge e:adj[1]){
		pq.push(e);
	}
	int ans=0,edges=0;
	while(!pq.empty()){
		edge e=pq.top();
		pq.pop();
		if(!vis[e.vertex]){
			vis[e.vertex]=true;
			ans+=e.dis;edges++;
			for(edge _e:adj[e.vertex]){
				pq.push(_e);
			}
		}
	}
	if(edges==n-1)
		cout<<ans;
	else
		cout<<"orz";
	return 0;
}
