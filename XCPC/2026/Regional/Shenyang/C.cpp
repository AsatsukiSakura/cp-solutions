#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
using pii=pair<int,int>;
const ll inf =1e16;
#define debug(x) cerr<<#x<<'='<<x<<' '
void solve(){
	int n,m,a,b,c;
	cin>>n>>m>>a>>b>>c;
	vector<int>op(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>op[i];
	vector<vector<int>>dp(m+1,vector<int>(m+1,inf));
	dp[0][0]=0;
	vector<int>mn(m+1,inf);
	mn[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(op[i]==j)continue;
			dp[op[i]][j]=min(dp[op[i]][j],min(dp[op[i]][j],dp[j][op[i]])+(b-a));
			dp[op[i]][j]=min(dp[op[i]][j],mn[j]+(c-a));
			mn[op[i]]=min(mn[op[i]],dp[op[i]][j]);
		}
	}
	int ans=*min_element(mn.begin(),mn.end());
	ans+=n*a;
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
