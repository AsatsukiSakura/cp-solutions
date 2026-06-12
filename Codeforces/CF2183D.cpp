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
void solve(){
	int n;
	cin>>n;
	vector<vector<int>>adj(n+1);
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int>q;
	vector<int>dis(n+1,inf),num(n+1),deg(n+1);
	for(int i=1;i<=n;i++){
		deg[i]=adj[i].size()+1/i;
	}
	dis[1]=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[u]){
			if(dis[v]==inf){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		num[dis[i]]++;
	}
	cout<<max(*max_element(deg.begin()+1,deg.end()),*max_element(num.begin(),num.end()))<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
