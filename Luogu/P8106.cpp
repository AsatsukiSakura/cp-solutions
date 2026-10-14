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
	vector<ll>fac(n+1,1);
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	auto C=[&](int x,int k){
		if(k<0 || k>x)return 0ll;
		return fac[x]*qp(fac[k],mod-2)%mod*qp(fac[x-k],mod-2)%mod;
	};
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(i*2!=n)
			ans+=C(n-2,i-1),ans%=mod;
	}
	cout<<ans<<'\n';
	return 0;
}
