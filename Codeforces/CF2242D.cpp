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
	string a,b;
	cin>>a>>b;
	int m=a.size(),n=b.size();
	a=' '+a;
	b=' '+b;
	vector<int>sa(m+1,0),sb(n+1,0);
	for(int i=1;i<=m;i++)
		sa[i]=(sa[i-1]+a[i]-'0')%10;
	for(int i=1;i<=n;i++)
		sb[i]=(sb[i-1]+b[i]-'0')%10;
	if(sa[m]!=sb[n]){cout<<"-1\n";return;}
	vector<vector<int>>dp(m+1,vector<int>(n+1,0));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(sa[i]==sb[j])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[m][n]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
