#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,n,m[301],dp[301][301],sum[301];
	cin>>n;
	sum[0]=0;
	for(i=1;i<=n;i++){
		cin>>m[i];
		sum[i]=sum[i-1]+m[i];
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			dp[i][j]=INT_MAX;
	for(i=1;i<=n;i++)	dp[i][i]=0;
	for(i=1;i<=n-1;i++){
		for(j=1;j<=n-i;j++){
			for(k=0;k<=i-1;k++){
				dp[j][j+i]=min(dp[j][j+i],dp[j][j+k]+dp[j+k+1][j+i]+sum[j+i]-sum[j-1]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
} 