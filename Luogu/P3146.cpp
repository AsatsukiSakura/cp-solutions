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
	vector<int>a(n+1);
	vector<vector<int>>dp(61,vector<int>(n+2,0));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[a[i]][i]=i+1;
	}
	int ans=0;
	for(int k=2;k<=60;k++){
		for(int i=1;i<=n;i++){
			if(!dp[k][i]&&dp[k-1][i]<=n)dp[k][i]=dp[k-1][dp[k-1][i]];
			if(dp[k][i])ans=k;
		}
	}
	cout<<ans;
	return 0;
}