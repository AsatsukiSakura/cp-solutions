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
void dfs(vector<int>&l,vector<int>&r,int p,int u,vector<int>&dp,vector<int>&dep){
	dep[u]=dep[p]+1;
	if(l[u]!=0){
		dfs(l,r,u,l[u],dp,dep);
		dfs(l,r,u,r[u],dp,dep);
	}
	dp[p]+=(dp[u]+2);
	dp[p]%=mod;
}
void dfs1(vector<int>&l,vector<int>&r,int p,int u,vector<int>&dp,vector<int>&ans){
	ans[u]=(ans[p]+dp[u])%mod;
	if(l[u]!=0){
		dfs1(l,r,u,l[u],dp,ans);
		dfs1(l,r,u,r[u],dp,ans);
	}
}
void solve(){
	int n;
	cin>>n;
	vector<int>l(n+1),r(n+1),f(n+1),dp(n+1,0),ans(n+1,0),dep(n+1);
	dep[0]=0;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	dfs(l,r,0,1,dp,dep);
	dfs1(l,r,0,1,dp,ans);
	for(int i=1;i<=n;i++){
		ans[i]=(ans[i]+dep[i])%mod;
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
