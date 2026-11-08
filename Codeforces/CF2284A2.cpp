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
	vector<ll>a(n+1);
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=1ll<<a[i];
		sum+=a[i];
	}
	sort(a.begin()+1,a.end(),greater<int>());
	ll ls=0;
	for(int i=1;i<=n;i++){
		if(2ll*(ls+a[i])<=sum)
			ls+=a[i];
	}
	cout<<1ll*ls*(sum-ls)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
