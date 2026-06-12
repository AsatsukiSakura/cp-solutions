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
void solve(){
	ll n,k;
	cin>>n>>k;
	int pc=__builtin_popcountll(n);
	if(n==0){cout<<max(0ll,k-1)<<endl;return;}
	if(k>=32){cout<<pc+k-1<<endl;return;}
	int dp[2][65][32];
	memset(dp,inf,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<=63;i++){
		int bt=(n>>i)&1ll;
		for(int j=0;j<=k;j++){
			for(int c=0;c<=1;c++){
				if(dp[c][i][j]==inf)continue;
				int sum=bt+c;
				dp[(bt+c)>>1][i+1][j]=min(dp[bt+c>>1][i+1][j],dp[c][i][j]+(bt+c&1));
				if(j<=k-1)
				dp[(bt+1+c)>>1][i+1][j+1]=min(dp[bt+1+c>>1][i+1][j+1],dp[c][i][j]+(bt+1+c&1));
				
			}
		}
	}
	for(int i=0;i<=64;i++){
		for(int j=0;j<=k;j++){
			cerr<<dp[0][i][j]<<' '<<dp[1][i][j]<<' ';
		}
		cout<<endl;
	}
	int ans=inf;
	for(int i=0;i<=k;i++){
		ans=min(ans,dp[0][64][i]);
	}
	cout<<pc-ans+k<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
