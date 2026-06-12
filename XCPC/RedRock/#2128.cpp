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
ll fact[10001],inv[10001];
ll qp(ll b,ll p){
	ll r=1;
	if(p<0)return 0;
	while(p){
		if(p&1){
			r*=b;
			r%=mod;
		}
		b*=b;
		b%=mod;
		p>>=1;
	}
	return r;
}
ll comb(ll x,ll k){
	if(k<0||k>x){
		return 0;
	}
	return fact[x]*inv[k]%mod*inv[x-k]%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,t;
	cin>>n>>m>>t;
	fact[0]=1;
	for(int i=1;i<=10000;i++){
		fact[i]=i*fact[i-1]%mod;
	}
	inv[10000]=qp(fact[10000],mod-2);
	for(int i=9999;i>=0;i--){
		inv[i]=(i+1)*inv[i+1]%mod;
	}
	ll ans=0;
	for(int i=t;i<=m;i++){
		ll c=comb(i,t)*((i-t)&1?-1:1);
		ll tmp=0;
		for(int j=0;j<=min(i,n);j++){
			tmp+=comb(m,i)*comb(n,j)%mod*fact[i]%mod*inv[i-j]%mod*qp(m-i,n-j)%mod;
			tmp%=mod;
		}
		ans=(ans+c*tmp%mod+mod)%mod;
	}
	cout<<ans%mod;
}
