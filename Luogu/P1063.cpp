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
	int n;
	cin>>n;
	vector<int>a(2*n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	vector<vector<int>>dp(2*n+1,vector<int>(2*n+1,0));
	for(int l=1;l<=n-1;l++){
		for(int i=1;i<=2*n-l;i++){
			for(int j=0;j<=l-1;j++){
				dp[i][i+l]=max(dp[i][i+l],dp[i][i+j]+dp[i+j+1][i+l]+a[i]*a[i+j+1]*a[i+l+1]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i][i+n-1]);
	}
	cout<<ans;
	return 0;
}
