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
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int c[2]={};
	for(int i=1;i<=n;i++)c[a[i]]++;
	vector<ll>fac(n+1,1),ifac(n+1);
	auto qp=[](ll b,ll p){
		ll r=1;
		while(p){
			if(p&1)
				r=r*b%mod;			
			p>>=1;
			b=b*b%mod;
		}
		return r;
	};
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	ifac[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	auto C=[&](int x,int y){
		if(y<0||y>x)return 0ll;
		return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
	};
	ll ans=0;
	for(int i=1;i<=min(k,c[1]);i++){
		if(k-i>=i)continue;
		ans+=1ll*C(c[1],i)*C(c[0],k-i)%mod;
		ans%=mod;
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
