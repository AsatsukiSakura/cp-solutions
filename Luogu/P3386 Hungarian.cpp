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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,e;
	cin>>n>>m>>e;
	vector<vector<int>>l(n+1);
	for(int i=1;i<=e;i++){
		int u,v;
		cin>>u>>v;
		l[u].push_back(v);
	}
	vector<int>match(m+1,0);
	vector<int>tag(m+1,0);
	int t=0;
	auto dfs=[&](auto &&self,int u)->bool{
		for(int v:l[u]){
			if(tag[v]==t)continue;
			tag[v]=t;
			if(match[v]==0||self(self,match[v])){
				match[v]=u;
				return true;
			}
		}
		return false;
	};
	int ans=0;
	for(int i=1;i<=n;i++){
		t++;
		if(dfs(dfs,i))ans++;
	}
	cout<<ans<<'\n';
}
