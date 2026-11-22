#include<bits/stdc++.h>
using namespace std;
#define int long long
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
const int inf = 0x3f3f3f3f;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	/*
	构造dfs序
	考虑根节点 d=0;
	考虑d=x节点
	构造其子节点 d=x+1;
	
	*/
	vector<int>a(n+1),e(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<vector<int>>adj(n+1);
	for(int i=1;i<=n;i++){
		cin>>e[i];
		for(int j=1;j<=e[i];j++){
			int x;
			cin>>x;
			adj[i].push_back(x);
		}
		sort(adj[i].begin(),adj[i].end(),[&](int x,int y){
			return a[x]<a[y];
		});
	}
	int mindep=inf;
	for(int i=1;i<=n;i++)
		mindep=min(mindep,a[i]);
	int rc=0,root=-1;
	for(int i=1;i<=n;i++)
		if(a[i]==mindep)rc++,root=i;
	if(root==-1||rc!=1||mindep!=0){
		cout<<"-1\n";
		return 0;
	}
	vector<vector<int>>order(n+1);
	vector<int>real(n+1,-1);
	auto dfs=[&](auto &&self,int p,int u)->void{
		real[u]=real[p]+1;
		for(int v:adj[u]){
			if(v==p)continue;
			if(real[v]==-1)order[u].push_back(v),self(self,u,v);
		}
	};
	dfs(dfs,0,root);
	for(int i=1;i<=n;i++){
		if(real[i]!=a[i]){
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<root<<'\n';
	for(int i=1;i<=n;i++){
		for(int x:adj[i])
			cout<<x<<' ';
		cout<<'\n';
	}
	cout<<'\n';
	return 0;
}
