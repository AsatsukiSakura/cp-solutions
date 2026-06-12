#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,l,r;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>l>>r;
	vector<int>f(n+1),dp(n+1);
	for(int i=0;i<=n;i++){
		cin>>f[i];
	}
	dp[0]=f[0];
	for(int i=1;i<=n;i++){
		int mx=-0x3f3f3f3f;
		for(int j=i-l;j>=i-r && j>=0;j--){
			mx=max(dp[j]+f[i],mx);
		}
		dp[i]=mx;
	}
	cout<<*max_element(dp.end()-r,dp.end());
	return 0;
}
//O(n^2)暴力
