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
	int n;cin>>n;
	ll sum=0;
	vector<ll>a(n+1);
	ll dp[2001][2001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][0]=0;
	for(int day=1;day<=n;day++){
		dp[0][day]=dp[0][day-1]+1ll*day*a[n+1-day];
		dp[day][0]=dp[day-1][0]+1ll*day*a[day];
		for(int i=1;i<day;i++){
			int j=day-i;
			dp[i][j]=max(dp[i-1][j]+1ll*day*a[i],dp[i][j-1]+1ll*day*a[n+1-j]);
		}
	}
	ll mx=-inf*inf;
	for(int i=0;i<=n;i++){
		int j=n-i;
		mx=max(dp[i][j],mx);
	}
	cout<<mx;
}
