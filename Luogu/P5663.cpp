#include<bits/stdc++.h>
const int INF=998244353;
using namespace std;
int main(){
	int i,j,n,m,q,u,v,a,l,dist[2][111111],p,visited[2][111111];
	memset(visited,0,sizeof(visited)); 
	cin>>n>>m>>q;
	vector<vector<int>> adj(n+1);
	queue<pair<int,int>> q_;
	for(i=1;i<=m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(i=1;i<=n;i++){
		dist[0][i]=dist[1][i]=INF;
	}
	dist[0][1]=0;
	q_.push({0,1});
	while(!q_.empty()){
		p=q_.front().first;
		i=q_.front().second;
		q_.pop();
		for(j=0;j<adj[i].size();j++)
			if(!visited[1-p][adj[i][j]]){
				q_.push({1-p,adj[i][j]});
				dist[1-p][adj[i][j]]=dist[p][i]+1;
				visited[1-p][adj[i][j]]=1;
			}			
		/*{p,x}=q_.pop{}
		遍历x节点所有相邻节点y
		如果 {1-p,y}这个状态没有被访问过 
		使{1-p,y} 入队
		dist[1-p][y]=dist[p][y]+1 */		
	}
	for(i=1;i<=q;i++){
		cin>>a>>l;
		if(dist[l%2][a]<=l) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
