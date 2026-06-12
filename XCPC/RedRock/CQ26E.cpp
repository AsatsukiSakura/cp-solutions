#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<int>b(n+1),c(n+1);
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	/*
	本质背包
	对于每一个bi算出需要几次操作
	然后注意到bi不会太大
	O(b^1.5 + n^2 logb)
	*/
	vector<int>d(1001,inf);
	d[1]=0;
	for(int i=1;i<=999;i++){
		for(int x=1;x*x<=i;x++){
			if(i+x<=1000)d[i+x]=min(d[i+x],d[i]+1);
			if(i+i/x<=1000)d[i+i/x]=min(d[i+i/x],d[i]+1);
		}
	}
	int m=*max_element(d.begin()+1,d.end())*n;
	if(k>=m){
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=c[i];
		}
		cout<<ans;
	}else{
		vector<ll>dp(k+1,0);
		for(int i=1;i<=n;i++){
			for(int j=k;j>=d[b[i]];j--){
				dp[j]=max(dp[j-d[b[i]]]+c[i],dp[j]);
			}
		}
		cout<<dp[k];
	}
	return 0;
}
