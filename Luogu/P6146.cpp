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
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1)r=r*b%mod;
		b=b*b%mod;
		p>>=1;
	}
	return r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<pii>a(n+1);
	vector<int>cnt(2*n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		cnt[a[i].second]++;
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=2*n;i++)cnt[i]+=cnt[i-1];
	vector<ll>dp(n+1,0);
	for(int i=1;i<=n;i++)
		dp[i]=(2ll*dp[i-1]+qp(2,cnt[a[i].first-1]))%mod;
	cout<<dp[n];
	return 0;
}
