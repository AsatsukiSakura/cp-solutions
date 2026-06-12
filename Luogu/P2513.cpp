#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=10000;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	int dp[1001][1001]={0};
	int sum[1001][1001]={0};
	cin>>n>>k;
	//dp[i][j]=dp[i-1][0]+.....dp[i-1][max(j,i)]
	dp[0][0]=1;
	for(int i=1;i<=k;i++)sum[0][i]=1;
	sum[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j-i<=-1)dp[i][j]=sum[i-1][j]%mod;
			else dp[i][j]=((sum[i-1][j]-sum[i-1][j-i])%mod+mod)%mod;
			if(j>0)sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
			else sum[i][j]=dp[i][j]%mod;
		}
	}
	cout<<dp[n][k]%mod;
	return 0;
}
