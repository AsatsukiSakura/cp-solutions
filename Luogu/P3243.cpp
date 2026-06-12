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
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	vector<int>in(n+1,0);
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[v].push_back(u);
		in[u]++;
	}
	vector<int>res;
	priority_queue<int>pq;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			pq.push(i);
		}
	}
	while(!pq.empty()){
		int u=pq.top();
		pq.pop();
		res.push_back(u);
		for(int v:adj[u]){
			in[v]--;
			if(in[v]==0)
				pq.push(v);
		}
	}
	if(res.size()<n)cout<<"Impossible!";
	else{
		for(auto it=res.rbegin();it!=res.rend();it++){
			cout<<*it<<' ';
		}
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
