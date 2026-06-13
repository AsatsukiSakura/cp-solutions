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
void solve(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	vector<vector<int>>adj(n);
	vector<int>dist(n,inf),mex(n);
	mex[s]=0;dist[t]=0;
	for(int i=0;i<n;i++){
		if(i==s)continue;
		if(i<s)mex[i]=i+1;
		if(i>s)mex[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int>q;q.push(t);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[u]){
			if(dist[v]==inf){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	int ans=inf;
	for(int i=0;i<n;i++){
		ans=min(ans,mex[i]+dist[i]);
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}