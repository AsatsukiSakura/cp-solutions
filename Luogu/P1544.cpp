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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<vector<ll>>a(n+1,vector<ll>(n+1));
	vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(n+1,vector<ll>(k+1,-0x3f3f3f3f3f3f3f3f)));
	dp[0][0].assign(k+1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			for(int z=0;z<=k;z++){
				dp[i][j][z]=max(dp[i-1][j][z]+a[i][j],dp[i-1][j-1][z]+a[i][j]);
				if(z>0){
					dp[i][j][z]=max(dp[i][j][z],dp[i-1][j][z-1]+3*a[i][j]);
					dp[i][j][z]=max(dp[i][j][z],dp[i-1][j-1][z-1]+3*a[i][j]);
				}
			}
	}
	ll mx=-0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			mx=max(dp[n][i][j],mx);
		}
	}
	cout<<mx;
	return 0;
}
