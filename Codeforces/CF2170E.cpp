#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>b(n+1,0);
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		b[r]=max(l,b[r]);
	}
	for(int i=1;i<=n;i++){
		b[i]=max(b[i-1],b[i]);
	}
	vector<ll>dp(n+1,0),sum(n+1,0);
	dp[0]=2;sum[0]=2;
	for(int i=1;i<=n;i++){
		if(b[i]>=1)dp[i]=sum[i-1]-sum[b[i]-1];
		else dp[i]=sum[i-1];
		dp[i]=(dp[i]+mod)%mod;
		sum[i]=sum[i-1]+dp[i];
		sum[i]%=mod;
	}
	cout<<dp[n]<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
