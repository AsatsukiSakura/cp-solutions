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
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end(),greater<int>());
	ll fn=1;
	for(int i=1;i<=n-1;i++)fn=fn*i%mod;
	ll s=a[1];
	auto qp=[](ll b,ll p){
		ll r=1;
		while(p){
			if(p&1)r=r*b%mod;
			b=b*b%mod;
			p>>=1;
		}
		return r;
	};
	ll ans=0;
	for(int i=2;i<=n;i++){
		ans+=fn*qp(i-1,mod-2)%mod*(s-1ll*a[i]*(i-1)%mod+mod)%mod;
		ans%=mod;
		s=(s+a[i])%mod;
		//debug(ans);
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
