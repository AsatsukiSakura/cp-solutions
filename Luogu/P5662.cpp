#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,m,w[114][114],i,j,k,dp[11011];
	cin>>t>>n>>m;	
	for(i=1;i<=t;i++)
		for(j=1;j<=n;j++)
			cin>>w[i][j];
	for(i=1;i<=t-1;i++){
		memset(dp,0,sizeof(dp));
		for(j=1;j<=n;j++){
			for(k=1;k<=m;k++){
				if(k>=w[i][j]) dp[k]=max(dp[k],w[i+1][j]-w[i][j]+dp[k-w[i][j]]);
			}
		}
		m+=dp[m];
	}
	cout<<m; 
}
