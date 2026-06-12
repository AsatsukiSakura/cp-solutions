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
ll qp(ll base,ll p){
	ll res=1;
	while(p!=0){
		if(p&1){
			res*=base;
			res%=mod;
		}
		p>>=1;
		base*=base;
		base%=mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll ilg=2;
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	int mx=*(a.end()-1);
	vector<ll>dp(mx+1,0);
	dp[0]=1ll;
	for(int i=1;i<=n-1;i++){
		for(int j=mx;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
		for(int j=0;j<=a[i+1];j++){
			ilg+=dp[j];
			ilg%=mod;
		}
	}
	ll ans=(qp(2,n)-ilg+mod)%mod;
	cout<<ans;
	return 0;
}
