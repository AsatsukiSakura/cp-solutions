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
	string s;
	int n;
	cin>>s>>n;
	s=' '+s;
	vector<vector<int>>num(s.size(),vector<int>(s.size(),0));
	for(int i=1;i<s.size();i++){
		for(int j=i;j<s.size();j++){
			num[i][j]=num[i][j-1]*10+s[j]-'0';
			if(num[i][j]>n)num[i][j]=n+1;
		}
	}
	
	vector<vector<int>>dp(s.size(),vector<int>(n+1,inf));
	dp[0][0]=-1;
	for(int i=1;i<s.size();i++){
		for(int j=i;j>=1&&num[j][i]<=n;j--){
			for(int k=num[j][i];k<=n;k++){
				dp[i][k]=min(dp[i][k],1+dp[j-1][k-num[j][i]]);
				
			}
		}
	}
	cout<<(dp[s.size()-1][n]==inf?-1:dp[s.size()-1][n]);
	return 0;
}
