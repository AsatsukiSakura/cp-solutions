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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin>>n;
	ll ans=0;
	auto cnt=[](ll a,ll b){
		return b/5+b/2-a/5-a/2-b/10+a/10;
	};
	auto S=[](ll x){
		ll r=0;
		for(ll i=1;i<=x;i*=5)
			r+=(int)__lg(x/i)+1;
		return r;
	};
	for(ll l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		ans+=(n/l)*(r-l+1-cnt(l-1,r))*S(n/l);
	}
	cout<<ans;
	return 0;
}
