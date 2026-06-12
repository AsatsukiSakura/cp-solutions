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
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1),b(n+1);
	vector<ll>dp(n+1,0),dp1(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		dp[i]=max(1ll*a[i],dp[i-1]+a[i]);
		dp1[i]=max(1ll*a[i]+b[i],max(dp1[i-1]+1ll*a[i],dp[i-1]+1ll*a[i]+1ll*b[i]));
	}
	if(k&1){
		cout<<*max_element(dp1.begin()+1,dp1.end());
	}
	else{
		cout<<*max_element(dp.begin()+1,dp.end());
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
