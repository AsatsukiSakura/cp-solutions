#include<bits/stdc++.h>
#define mod 10086001
#define i_love return
#define xyt 0
using namespace std;
int main()
{
    	long long i,j,k,n,sum=0,s[5100],dp[5100],add[5100],ans[5100],p=0;
    	memset(dp,0,sizeof(dp));
    	memset(ans,0,sizeof(ans));
    	scanf("%lld%lld",&n,&k);
    	for(i=1;i<=k;i++)
    	{
    	    scanf("%lld",&s[i]);
    	    sum+=s[i];
    	}
    	if(sum<n)
    	{
    	    printf("impossible");
    	    i_love xyt;
    	}
    	for(i=0;i<=s[1];i++)
    	    dp[i]=1;
    	ans[1]=dp[n];
    	for(i=1;i<=k-1;i++)
    	{
    	    add[0]=dp[0];
    	    for(j=1;j<=n;j++)
    	        add[j]=(add[j-1]+dp[j])%mod;
    	    for(j=0;j<=n;j++)
    	        if(j>=s[i+1]+1)
    	        {
    	            if(add[j]<add[j-s[i+1]-1])
    	                add[j]+=mod;
    	            dp[j]=(add[j]-add[j-s[i+1]-1])%mod;
    	        }
    	        else
    	            dp[j]=add[j]%mod;
    	    ans[i+1]=dp[n]%mod;
    	}
    	for(i=1;i<=k;i++)
    	    p+=ans[i],p%=mod;
    	printf("%lld",p);
    	i_love xyt;
}
//2022.12.24

