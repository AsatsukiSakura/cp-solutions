#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	vector<vector<vector<bool>>>r(31,vector<vector<bool>>(n+1,vector<bool>(n+1,false)));
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		r[0][u][v]=true;
	}
	for(int l=0;l<=29;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++){
					r[l+1][j][k]=r[l+1][j][k]||(r[l][j][i]&&r[l][i][k]);
					if(r[l+1][j][k])adj[j].push_back(k);
				}
	vector<int>dist(n+1,inf);
	queue<int>q;
	q.push(1);
	dist[1]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[u]){
			if(dist[v]==inf)q.push(v);
			dist[v]=min(dist[u]+1,dist[v]);
		}
	}
	cout<<dist[n];
	return 0;
}
