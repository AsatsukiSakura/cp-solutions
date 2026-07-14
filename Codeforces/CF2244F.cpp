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
const pii wysi={-727,inf};
void solve(){
	int n;
	cin>>n;
	vector<vector<int>>adj(n+1);
	for(int i=2;i<=n;i++){
		int p;
		cin>>p;
		adj[p].push_back(i);
	}
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	auto dfs=[&](auto self,int u)->pii{
		if(adj[u].empty())
			return {a[u],a[u]};
		vector<pii>prs;
		vector<int>mn;
		for(int v:adj[u]){
			pii res=self(self,v);
			if(res.first==-727) return wysi;
			prs.push_back(res);
			mn.push_back(res.first);
		}
		vector<pii>prt=prs;
		sort(prt.begin(),prt.end());
		for(int i=0;i<(int)prt.size()-1;i++)
			if(prt[i].second+1!=prt[i+1].first)
				return wysi;
		int d=0;
		for(int i=0;i<mn.size();i++){
			if(mn[i]>mn[(i+1)%mn.size()]) d++;
		}
		if(d>1)	return wysi;
		return {prt.front().first,prt.back().second};
	};
	pii ans=dfs(dfs,1);
	if(ans.first==-727) cout<<"NO\n";
	else cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
