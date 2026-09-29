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
	int n;
	cin>>n;
	vector<vector<ll>>s(n+1,vector<ll>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
	}
	vector<vector<ll>>dp(n+1,vector<ll>(1<<n,inf<<30));
	dp[1][1]=0;
	for(int st=1;st<(1<<n);st++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((st&(1<<(j-1)))&&!(st&(1<<(i-1))))
					dp[i][st|(1<<i-1)]=min(dp[i][st|(1<<i-1)],dp[j][st]+s[j][i]);
			}
		}
	}
	ll ans=inf<<30;
	for(int i=2;i<=n;i++){
		ans=min(ans,dp[i][(1<<n)-1]);
	}
	cout<<ans<<'\n';
	return 0;
}
