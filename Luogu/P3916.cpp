#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
vector<int>a;
vector<vector<int>>adj;
void dfs(int i,int j){
	a[j]=i;
	for(int x:adj[j]){
		if(a[x]==0){
			dfs(i,x);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	a.resize(n+1,0);
	adj.resize(n+1);
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[v].push_back(u);
	}
	for(int i=n;i>=1;i--){
		if(a[i]==0){
			dfs(i,i);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
