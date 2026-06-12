#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	ll dp[k+1]={0};
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=k;j>=1;j--){
			dp[j]=(dp[j]+dp[j-1]*a[i])%mod;
		}
	}
	cout<<dp[k];
	return 0;
}
