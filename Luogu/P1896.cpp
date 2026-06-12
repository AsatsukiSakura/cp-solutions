#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k,dp[11][1<<10][100],i,j,prev,cnt,ans=0,num[1<<10];
	cin>>n>>k;
	for(i=0;i<=(1<<n)-1;i++)
		num[i]=__builtin_popcount(i); 
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=(1<<n)-1;j++){
			if((j&(j>>1))==0){
				for(prev=0;prev<=(1<<n)-1;prev++){
					if((prev&(prev>>1))==0 && (prev&j)==0 && (prev&(j>>1))==0 && (prev&(j<<1))==0){
						for(cnt=num[j];cnt<=k;cnt++){
							dp[i][j][cnt]+=dp[i-1][prev][cnt-num[j]];
						}
					}
				}
			}
		}
	}
	for(i=0;i<=(1<<n)-1;i++)
		ans+=dp[n][i][k];
	cout<<ans; 
}
