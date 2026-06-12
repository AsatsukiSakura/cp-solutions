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
	vector<int>dp(32,0);
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=0;j<=31;j++){
			if((1<<j)&a[i]){
				mx=max(mx,dp[j]);
			}
		}
		for(int j=0;j<=31;j++){
			if((1<<j)&a[i]){
				dp[j]=mx+1;
			}
		}
	}
	cout<<*max_element(dp.begin(),dp.end());
	return 0;
}
