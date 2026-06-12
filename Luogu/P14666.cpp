#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
const int _=1e6;
vector<int>adj[_+1];
int fa[_+1];
ll w[_+1],cnt[_+1];
bool on[_+1];
void dfs1(int p,int u){
	for(int v:adj[u]){
		if(v!=p){
			fa[v]=u;
			dfs1(u,v);
		}
	}
}
void dfs2(int p,int u){
	w[u]=1;
	cnt[u]=0;
	vector<int>valid(1);//占位
	for(int v:adj[u]){
		if(v!=p){
			dfs2(u,v);
			if(!on[v]){
				w[u]*=(w[v]+(u!=1));
				w[u]%=mod;
				valid.push_back(v);//有效子节点
			}
		}
	}
	int n=valid.size()-1;
	if(n==0)return;//有效子结点个数+1
	vector<ll>pre(n+1,1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]*(w[valid[i]]+(u!=1))%mod;
	}
	vector<ll>suf(n+2,1);
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1]*(w[valid[i]]+(u!=1))%mod;
	}
	for(int i=1;i<=n;i++){
		int v=valid[i];
		cnt[u]+=pre[i-1]*suf[i+1]%mod*(2*w[v]+cnt[v])%mod;
		cnt[u]%=mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,s;
	cin>>n>>s;
	for(int i=1;i<=n-1;i++){
		int u,v;		
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fa[1]=0;
	dfs1(1,1);
	vector<int>path(1);
	for(int i=s;i!=0;i=fa[i]){
		on[i]=true;
		path.push_back(i);
	}
	dfs2(1,1);
	int l=path.size()-1;
	vector<ll>pre(l+1,1),suf(l+2,1);
	for(int i=1;i<=l;i++){
		pre[i]=pre[i-1]*w[path[i]]%mod;
	}
	for(int i=l;i>=1;i--){
		suf[i]=suf[i+1]*w[path[i]]%mod;
	}
	ll ans=0;
	for(int i=1;i<=l;i++){
		ans+=pre[i-1]*suf[i+1]%mod*cnt[path[i]]%mod;
		ans%=mod;
	}
	ans+=pre[l]*(l-1)%mod;ans%=mod;
	cout<<ans;
	return 0;
}
/*
7 3
1 2
2 3
1 4
2 5
2 6
3 7
*/
