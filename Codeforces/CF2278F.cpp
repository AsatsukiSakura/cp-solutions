#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=998244353;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<ll>>dp(n+1,vector<ll>(m+3,0));
	vector<ll>sum(m+3,0);
	dp[1][2]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m+2;j++)sum[j]=(sum[j-1]+dp[i-1][j])%mod;
		for(int j=2;j<=m+2;j++){
			dp[i][j]=(sum[j]-sum[(j+2)/2-1]+mod)%mod;
			//v<=j<=2v-1
			//j>=v 	j+1<=2v -> v>=upper((j+1)/2)
		}
	}
	ll ans=0;
	for(int i=2;i<=n;i++){
		ans=(ans+dp[i][m+2])%mod;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
