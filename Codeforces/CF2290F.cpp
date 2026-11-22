#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>dp(n+1);
	vector<int>sum(n+1,0);
	int ans=0;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]&=1;
	dp[1]=1,sum[1]=1;
	for(int i=1;i<=n;i++){
		dp[i]=(1+sum[i-1]-sum[max(0,i-k-1)])&1;
		sum[i]=(sum[i-1]+dp[i])&1;
		ans+=a[i]*dp[i];
		ans&=1;
	}
	cout<<(ans?"Alice":"Bob")<<'\n';
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
