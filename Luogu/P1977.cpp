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
	int n,k,d,s;
	cin>>n>>k>>d>>s;
	vector<pii>tz(k+1);
	for(int i=1;i<=k;i++){
		cin>>tz[i].first>>tz[i].second;
	}
	tz[0]={0,0};
	sort(tz.begin(),tz.end());
	vector<vector<int>>dp(k+1,vector<int>(n+1,inf));
	dp[0][0]=0;
	for(int i=1;i<=k&&tz[i].first<=s;i++){
		for(int j=0;j<=n;j++){
			int p=j+tz[i].second;
			p=p>n?n:p;
			int t=tz[i].first-tz[i-1].first;
			dp[i][p]=min(dp[i][p],dp[i-1][j]+(n-j)*t+d);
			dp[i][j]=min(dp[i][j],dp[i-1][j]+(n-j)*t);
		}
	}
	int m=inf;
	for(int i=0;i<=k;i++){
		m=min(m,dp[i][n]);
	}
	if(m==inf)cout<<"impossible";
	else cout<<m;
	return 0;
}
