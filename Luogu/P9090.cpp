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
struct node {
	int lc,rc;
};
void dfs(int u,vector<node>&tree,vector<int>*dp) {
	if (tree[u].lc) {
		dfs(tree[u].lc,tree,dp);
		int l=tree[u].lc;
		dp[0][u]+=max(dp[0][l],dp[1][l]);
		dp[1][u]+=dp[0][l];
	}
	if (tree[u].rc) {
		dfs(tree[u].rc,tree,dp);
		int r=tree[u].rc;
		dp[0][u]+=max(dp[0][r],dp[1][r]);
		dp[1][u]+=dp[0][r];  
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	vector<int>mis[2][2];
	mis[0][0]=mis[1][0]=mis[1][1]=mis[0][1]=vector<int>(n+1);
	vector<node>c(n+1);
	for(int i=1; i<=n; i++) {
		int l,r;
		cin>>l>>r;
		c[i].lc=l;
		c[i].rc=r;
	}
	vector<int>dp[2];
	dp[0].assign(n+1,0);
	dp[1].assign(n+1,1);
	dfs(1,c,dp);
	for(int i=1; i<=n; i++) {
		mis[1][1][i]=max(dp[1][i],dp[0][i]);
		mis[0][1][i]=dp[0][i];
	}
	int	rn=1;
	while(c[rn].rc!=0)
		rn=c[rn].rc;
	dp[0].assign(n+1,0);
	dp[1].assign(n+1,1);
	dp[1][rn]=0;
	dfs(1,c,dp);
	for(int i=1; i<=n; i++) {
		mis[1][0][i]=max(dp[1][i],dp[0][i]);
		mis[0][0][i]=dp[0][i];
	}
	cout<<mis[1][1][1];
	vector<int>ans[2][2];
	ans[0][0]=ans[1][0]=ans[1][1]=ans[0][1]=vector<int>(n+1);
	while(q--){
		int x,ii;
		cin>>x>>ii;
		ans[0][0][1]=max(mis[0][1][ii]+mis[0][0][ii],mis[0][0][ii]+mis[1][0][ii]);
		ans[1][0][1]=max(mis[1][0][ii]+mis[1][0][ii],mis[1][1][ii]+mis[0][0][ii]);
		ans[0][1][1]=max(mis[0][0][ii]+mis[1][1][ii],mis[0][1][ii]+mis[0][1][ii]);
		ans[1][1][1]=max(mis[1][0][ii]+mis[1][1][ii],mis[1][1][ii]+mis[0][1][ii]);
		for(int i=2;i<=x;i++){
			ans[0][0][i]=max(3*ans[1][1][i-1]+ans[1][0][i-1],
							 1+ans[1][1][i-1]+ans[1][0][i-1]+ans[0][1][i-1]+ans[0][0][i-1]);
			ans[1][0][i]=max(1+2*ans[0][1][i-1]+ans[0][1][i-1]+ans[1][1][i-1])
		}
	}
	return 0;
}
