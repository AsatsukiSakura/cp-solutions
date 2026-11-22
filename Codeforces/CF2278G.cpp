#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const double eps=1e-8;
void solve(){
	int n;
	cin>>n;
	vector<vector<int>>tree(n+1);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	string x,y;
	vector<int>d(n+1,0);
	cin>>x>>y;
	x=' '+x,y=' '+y;
	vector<int>dep(n+1,0);
	dep[1]=0;
	auto dfs=[&](auto &&self,int p,int u)->void{
		d[u]+=y[u]-x[u];
		for(int v:tree[u]){
			if(v==p)continue;
			dep[v]=dep[u]+1;
			if(d[u]<0)d[v]--;
			self(self,u,v);		
		}
		if(d[u]<0)d[u]+=2;
	};
	dfs(dfs,0,1);
	int mxdep=*max_element(dep.begin()+1,dep.end());
	vector<int>cnt(mxdep+1,0),sum(mxdep+1,0);
	for(int i=1;i<=n;i++)
		cnt[dep[i]]++,sum[dep[i]]+=d[i];
	int cn=0;
	for(int i=1;i<=mxdep;i++)
		cn+=(cnt[i]==sum[i]||sum[i]==0);
	if(cn!=mxdep){cout<<"-1\n";return;}
	ll ans=0;
	for(ll i=0,f=1;i<=mxdep;i++,f<<=1,f%=mod)
		ans=(ans+f*(sum[i]==0?0:1))%mod;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
