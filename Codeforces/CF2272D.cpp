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
struct tree{
	int sz,kp;
	vector<vector<int>>adj,dp;
	void init(int n){
		sz=n;
		kp=1;
		adj.resize(sz+1);
		dp.assign(sz+1,vector<int>(2,0));
	}
	void dfs(int p,int u){
		dp[u][0]=0;
		dp[u][1]=1;
		for(int v:adj[u]){
			if(v==p)continue;
			dfs(u,v);  
			dp[u][0]+=max(dp[v][0],dp[v][1]);
			dp[u][1]+=dp[v][0];
		}
		if(dp[u][0]>=dp[u][1])kp=u;
	}
};
void solve(){
	int k,x=-1;
	cin>>k;
	vector<tree>tr(k+1);
	for(int i=1;i<=k;i++){
		int n;
		cin>>n;
		tr[i].init(n);
		if(tr[i].sz>=2)
			x=i;
		for(int j=1;j<tr[i].sz;j++){
			int u,v;
			cin>>u>>v;
			tr[i].adj[u].push_back(v);
			tr[i].adj[v].push_back(u);
		}
	}
	int rt=1,rp=1;
	if(x!=-1){
		tr[x].dfs(1,0);
		rt=x;
		rp=tr[x].kp;
	}
	for(int i=1;i<=k;i++){
		if(i==rt)continue;
		cout<<rt<<" "<<rp<<" "<<i<<" 1\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
