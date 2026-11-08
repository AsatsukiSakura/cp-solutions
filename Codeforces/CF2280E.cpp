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
	int n,l;
	cin>>n>>l;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	vector<ll>sum(n+1,0);
	for(int i=1;i<=n-1;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=1e18;
	for(int val=0,i=0;val*val<=l-1;val++){
		int tar=val==0?a[n]:min((l-1)/val,a[n]);
		while(i<n&&a[i]<=val)i++;
		ans=min(ans,(sum[n-1]-sum[i-1])-1ll*(n-i)*val+a[n]-tar);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
