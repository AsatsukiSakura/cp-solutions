#include<bits/stdc++.h>
#define mod 1000000007
using namespace std; 
int main(){
	int i,n,a[10492],dp[10492],mx,mn,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(dp,0,sizeof(dp));
	dp[0]=1; 
	for(i=1;i<=n;i++){
		mx=0;mn=n+1;	
		for(j=i;j>=1;j--){
			if(a[j]>mx) mx=a[j];
			if(a[j]<mn) mn=a[j]; 
			if(i-j==mx-mn){
				dp[i]+=dp[j-1];dp[i]%=mod; 
			}
		}	
	}
	cout<<dp[n];
	return 0; 
} 
