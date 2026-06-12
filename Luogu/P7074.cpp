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
	int n,m;
	cin>>n>>m;
	vector<vector<int>>a(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	array<vector<vector<ll>>,2>dp={
		vector<vector<ll>>(n+2,vector<ll>(m+2,-inf))
		,vector<vector<ll>>(n+2,vector<ll>(m+2,-inf))
	};
	dp[0][1][1]=dp[1][1][1]=a[1][1];
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(i!=1 || j!=1)
			dp[0][i][j]=max({dp[0][i][j-1],dp[1][i][j-1],dp[0][i-1][j]})+a[i][j]*1ll;
		}
		for(int i=n;i>=1;i--){
			if(j!=1)
			dp[1][i][j]=max({dp[0][i][j-1],dp[1][i][j-1],dp[1][i+1][j]})+a[i][j]*1ll;
		}
	}
	cout<<max(dp[1][n][m],dp[0][n][m]);
	return 0;
}
