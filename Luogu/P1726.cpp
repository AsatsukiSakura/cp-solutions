#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int tt=0;
vector<vector<int>>adj,sccs;
vector<int>t,low,inst;
stack<int>st;
bool cmp(vector<int>x,vector<int>y){
	if(x.size()!=y.size()) return x.size()>y.size();
	return x<y;
}
void dfs(int u){
	t[u]=low[u]=++tt;
	st.push(u);
	inst[u]=true;
	for(int v:adj[u]){
		if(!t[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(inst[v]){
			low[u]=min(low[u],t[v]);
		}
	}
	if(t[u]==low[u]){
		vector<int>scc;
		while(!st.empty()) {
			inst[st.top()]=0;
			scc.push_back(st.top());
			if(st.top()==u){
				st.pop();break;
			}
			st.pop();
		}
		sort(scc.begin(),scc.end());
		sccs.push_back(scc);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;cin>>n>>m;
	adj.resize(n+1);inst.resize(n+1,0);
	t.resize(n+1,0);low.resize(n+1,0);
	while(m--){
		int u,v,tp;	
		cin>>u>>v>>tp;
		adj[u].push_back(v);
		if(tp==2)	adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!t[i])	dfs(i);
	}
	sort(sccs.begin(),sccs.end(),cmp);
	cout<<(*sccs.begin()).size()<<endl;
	for(int i:*sccs.begin()){
		cout<<i<<' ';
	}
	return 0;
}
