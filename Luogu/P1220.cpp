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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,c;
	vector<int>a(n+1),p(n+1),sum(n+1,0);
	int dp[2][n+1][n+1];
	memset(dp,inf,sizeof dp);
	
	for(int i=1;i<=n;i++){
		cin>>p[i]>>a[i];
		sum[i]+=a[i];
	}
	dp[0][c][c]=dp[1][c][c]=0;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n;i++){
			dp[0][i][i-1+len]=min(dp[0][i+1][i-1+len]+(a[i+1]-a[i])*)
			
		}
	}
	return 0;
}
