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
	string a,b;
	cin>>a>>b;
	vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
	for(int i=0;i<=a.size();i++)
		dp[i][0]=i;
	for(int i=0;i<=b.size();i++)
		dp[0][i]=i;
	for(int i=1;i<=a.size();i++){
		for(int j=1;j<=b.size();j++){
			if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
		}
	}
	cout<<dp[a.size()][b.size()];
	return 0;
}
