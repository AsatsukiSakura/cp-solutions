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
struct Node{
	int cnt=0;
	int nxt[2]={0,0};
};
struct Trie{
	vector<Node>tree;
	Trie(){
		tree.emplace_back();
	}
	void insert(int x){
		int u=0;
		for(int i=30;i>=0;i--){
			int bit=(x>>i)&1;
			if(!tree[u].nxt[bit]){
				tree[u].nxt[bit]=tree.size();
				tree.emplace_back();
			}
			u=tree[u].nxt[bit];
			tree[u].cnt++;
		}
	}
	int query(int x){
		int u=0;
		int r=0;
		for(int i=30;i>=0;i--){
			int bit=(x>>i)&1;
			if(tree[u].nxt[1^bit]){
				u=tree[u].nxt[1^bit];
				r+=(1<<i);
			}
			else u=tree[u].nxt[bit];
		}
		return r;
	}
};
struct Edge{
	int v,w;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<vector<Edge>>a(n+1);
	for(int i=1;i<=n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	vector<int>val(n+1,0);
	auto dfs=[&](auto &&self,int p,int u)->void{
		for(Edge e:a[u]){
			if(e.v!=p){
				val[e.v]=e.w^val[u];
				self(self,u,e.v);
			}
		}
	};
	dfs(dfs,0,1);
	Trie tr;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,tr.query(val[i]));
		tr.insert(val[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
