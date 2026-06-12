#include<bits/stdc++.h>
using namespace std;
int dist[456][456];
int dx[9]={114514,-2,-2,2,2,1,-1,1,-1};
int dy[9]={1919810,-1,1,-1,1,2,-2,-2,2};
int n,m,x,y,i,j;
queue<pair<int,int> > q;
void bfs(pair<int,int> p){
	q.push(p);	
	while(!q.empty()){
		for(int i=1;i<=8;i++)
		if(q.front().first+dx[i]>0 && q.front().first+dx[i]<=n && q.front().second+dy[i]>0 && q.front().second+dy[i]<=m)
		if(dist[q.front().first+dx[i]][q.front().second+dy[i]]==-1){
			q.push({q.front().first+dx[i],q.front().second+dy[i]});
			dist[q.front().first+dx[i]][q.front().second+dy[i]]=dist[q.front().first][q.front().second]+1;
		}	
		q.pop();
	}
}
int main(){
	cin>>n>>m>>x>>y;
	memset(dist,-1,sizeof(dist));
	dist[x][y]=0;
	bfs({x,y});
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<dist[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
