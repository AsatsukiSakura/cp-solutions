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
	string s;
	cin>>n>>s;
	s=' '+s;
	vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(10,vector<ll>(1024,0)));
	for(int i=1;i<=n;i++){
		int x=s[i]-'A';
		for(int mask=1;mask<1024;mask++)
			for(int j=0;j<=9;j++)
				dp[i][j][mask]=dp[i-1][j][mask];
		dp[i][x][1<<x]++,dp[i][x][1<<x]%=mod;
		for(int mask=1;mask<1024;mask++){
			for(int j=0;j<=9;j++){
				if(x==j)dp[i][x][mask]+=dp[i-1][x][mask],
					dp[i][x][mask]%=mod;
				else if(((1<<x)&mask)==0)dp[i][x][mask|(1<<x)]+=dp[i-1][j][mask],
					dp[i][x][mask|(1<<x)]%=mod;
			}
		}
	}
	ll ans=0;
	for(int mask=1;mask<1024;mask++)
		for(int j=0;j<=9;j++)
			ans+=dp[n][j][mask],ans%=mod;
	cout<<ans;
	return 0;
}
