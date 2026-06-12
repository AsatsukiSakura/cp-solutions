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
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<ll>sum(n+1,0),abssum(n+1,0);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		abssum[i]=abssum[i-1]+(i==1?a[i]:abs(a[i]));
	}
	ll ans=-inf*inf;
	for(int i=1;i<=n;i++){
		ans=max(ans,abssum[i-1]+sum[i]-sum[n]);
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
