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
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1,0);
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1,j=n;i<=min(k-1,n-k+1);i++,j--){
		ans+=max(a[i],a[j]);
	}
//	debug(ans);
//	debug(n-k);
	for(int i=k;i<=n-k+1;i++)
		ans+=a[i];
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
