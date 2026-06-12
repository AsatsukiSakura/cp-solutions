#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<vector<int>>dp(k+1,vector<int>(n+1,0));
	for(int b=1;b<=n-1;b++){
		dp[1][b]=1;
		for(int j=2;j<=k;j++){
			for(int i=1;i<=n-b;i++){
				dp[j][i+b]+=dp[j-1][i];
			}
		}
	}
	cout<<dp[k][n];
	return 0;
}
