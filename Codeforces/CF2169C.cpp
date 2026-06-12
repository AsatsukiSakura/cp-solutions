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
void solve(){
	int n;
	ll sum=0;
	cin>>n;
	vector<int>a(n+1),v(n+1);
	vector<ll>dp(n+1,-1ll*inf*inf);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i]=2*i-a[i];
		sum+=1ll*a[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1]+v[i],1ll*v[i]);
	}
	cout<<sum+1ll**max_element(dp.begin(),dp.end())<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
