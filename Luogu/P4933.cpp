#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<unordered_map<int,int>>dp(n+1);
	ll ans=n;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			dp[i][a[i]-a[j]]+=dp[j][a[i]-a[j]]+1;
			dp[i][a[i]-a[j]]%=mod;
			ans+=dp[j][a[i]-a[j]]+1;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
