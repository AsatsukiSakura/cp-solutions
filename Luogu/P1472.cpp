#include<bits/stdc++.h>
using namespace std;
const int mod=9901;
int main(){
	int i,j,p,k,n,dp[234][123];
	cin>>n>>k;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=k;i++)	dp[1][i]=1;
	for(i=3;i<=n;i+=2){
		for(j=1;j<=k;j++){
			for(p=1;p<=i-1;p+=2){
				dp[i][j]+=dp[p][j-1]*dp[i-1-p][j-1];
				dp[i][j]%=mod;
			}
		}
	}
	cout<<(dp[n][k]-dp[n][k-1]+mod)%mod;
	return 0;
}
