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
	int n,k;
	cin>>n>>k;
	vector<vector<int>>adj(n+1);
	vector<int>dist(n+1,inf);
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	queue<int>q;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[u]){
			dist[u]=min(dist[v]+1,dist[u]);
		}
	}
	cout<<(dist[k]==inf?-1:dist[k]);
	return 0;
}
