#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
vector<vector<int>>color;
vector<vector<ll>>dp;
vector<vector<int>>adj;
vector<ll>sum;
void dfs(int p,int u){	
	for(int v:adj[u]){
		if(v==p)continue;
		dfs(u,v);
	}	
	if(p==u)return;
	for(int c:color[u]){
		sum[u]=(sum[u]+dp[u][c])%mod;	
	}
	for(int c:color[p]){
		dp[p][c]=(dp[p][c]*(sum[u]-dp[u][c]+mod)%mod)%mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;cin>>n>>m;
	color.resize(n+1);
	adj.resize(n+1);
	dp.resize(n+1,vector<ll>(m+1,0));
	sum.resize(n+1,0);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int c;
			cin>>c;
			color[i].push_back(c);
			dp[i][c]=1;
		}
	}
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,1);
	int sum=0;
	for(int c:color[1]){
		sum=(sum+dp[1][c])%mod;
	}
	cout<<sum;
	return 0;
}
/*3 3
3 1 2 3
3 1 2 3
3 1 2 3
1 2
1 3
2 2
2 1 2
2 1 2
1 2
4 3
3 1 2 3
3 1 2 3
3 1 2 3
3 1 2 3
1 2
1 3
1 4

4 2
2 1 2
2 1 2
1 2
1 2
1 2
2 3
2 4*/


