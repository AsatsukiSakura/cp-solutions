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
	int s=0;
	vector<int>a(n+1);
	vector<vector<int>>p(k);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	p[0].push_back(0);
	ll ans=0;
	for(int i=1;i<=n;i++){
		s+=a[i],s%=k;
		p[s].push_back(i);
		int cnt=lower_bound(p[s].begin(),p[s].end(),i-k)-p[s].begin();
		ans+=cnt;
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
