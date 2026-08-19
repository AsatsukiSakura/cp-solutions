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
	int n,c;
	cin>>n>>c;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.end());
	vector<ll>sum(n+1,0);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ll mx=-2e18;
	for(int i=0;i*2<=n;i++)
		mx=max(sum[n]-sum[i]-1ll*c*(n-i),mx);
	cout<<mx<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
