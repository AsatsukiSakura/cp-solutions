#include<bits/stdc++.h>
using namespace std;
/*int main(){
	int n,i,j;
	double ps,psb;
	cin>>n;
	vector<double> p(n+1),dp(n+1);
	for(i=1;i<=n;i++){
		cin>>p[i];
	}
	dp[0]=0;p[0]=0;
	for(i=1;i<=n;i++){
		dp[i]=dp[i-1];
		ps=p[i];
		for(j=i;j>=1;j--){
			psb=ps*(1-p[j-1]);
			dp[i]+=psb*(3*(i-j)*(i-j)+3*(i-j)+1);
			ps*=p[j-1];
		}
	}
	printf("%.1lf",dp[n]); 
	return 0;
}
优化前的O(n2)做法*/
/*(n+1)3-n3=3n2+3n+1 O(n2) 
需要空间换时间
这份代码在检查到每个i时都要计算所有[j,i]的期望，O(n)复杂度计算连上这个加分的期望 
在dp时递推的算出下一个连上加分的期望 观察到加分等于E(2l2+2l+1)=1+2E(l2)+E(l)+1
 设el(i)等于到i时 qianmian的最后段长期望，那么el(i+1)是多少呢？
记pl(i,j)=连到第i个时前面（包括自己）已经连了j个的概率。 
el(i)=sigma(pl(i,j)*j))j from 0 toi  el(i+1)=sigma(pl(i+1,j)*j) j:0toi+1 注意到pl(i+1,j)=p(i+1)*pl(i,j-1) 
el(i+1)=0*(1-p(i+1))+p(i+1)*sigma(pl(i,j-1)*j) j从1到i+1,=sigma(pl(i,k)*k+pl(i,k)) k从0到i 
非常不容易的的注意到sigma(pl(i,k))=1 !!!!!
el(i+1)=p(i+1)*(el(i)+1)
记pl(i,j)=连到第i个时前面（包括自己）已经连了j个的概率。
el2(i)=sigma(pl(i,j)*j^2) el2(i+1)=sigma(pl(i+1,j)*j^2) j:0toi+1 注意到pl(i+1,j)=p(i+1)*pl(i,j-1)
el2(i+1)=0*(1-p(i+1))+p(i+1)*sigma(pl(i,j-1)*j^2) j从1到i+1,=sigma(pl(i,k)*k^2+2*pl(i,k)*k+1) k从0到i 
el2(i+1)=p(i+1)*(el2(i)+2*el(i)+1)
所以el(i)和el2(i)可以转移得到！
el(i-1)是i-1步完成时l的期望 所以e(i)应该由el(i-1)转移得来而不是e(i) 
同时空间可以优化，每个状态都只由他的前一个状态转移得来，所以O(n)可以优化到O1! 
*/ 
int main(){
	int n,i;
	double e=0,e1=0,e2=0;
	cin>>n;
	vector<double> p(n+1);
	for(i=1;i<=n;i++)	cin>>p[i];
	for(i=1;i<=n;i++){
		e+=p[i]*(1+3*e2+3*e1);
		e2=p[i]*(e2+2*e1+1);
		e1=p[i]*(e1+1);
	}
	printf("%.1lf",e);
	return 0;
}

