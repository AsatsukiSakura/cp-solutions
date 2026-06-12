#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=80112002;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	vector<int>tp(n+1),in(n+1,0),dp(n+1,0);
	queue<int>q;
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		in[v]++;
	}
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			dp[i]=1;
			q.push(i);
		}
	}		
	while(!q.empty()){
	int u=q.front();
	tp.push_back(u);				
	q.pop();
	for(int v:adj[u])
		if(--in[v]==0)
			q.push(v);
	}
	for(int u:tp){
		for(int v:adj[u]){
			dp[v]+=dp[u];
			dp[v]%=mod;
		}
	}
	int ans=0;
	for(int u:tp){
		if(adj[u].empty()){
			ans+=dp[u];
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
