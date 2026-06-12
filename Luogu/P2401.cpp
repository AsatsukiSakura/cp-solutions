#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=2015;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<vector<int>>dp(n+1,vector<int>(k+1,0));
	dp[1][0]=1;
	for(int i=2;i<=n;i++){
		dp[i][0]=1;
		for(int j=1;j<=min(i-1,k);j++){
			dp[i][j]+=(i-j)*dp[i-1][j-1];
			dp[i][j]+=(j+1)*dp[i-1][j];
			dp[i][j]%=mod;
		}
	}
	cout<<dp[n][k];
	return 0;
}
