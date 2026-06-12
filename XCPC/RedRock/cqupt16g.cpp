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
ll qp(ll x,ll k){
	ll res=1;
	while(k){
		if(k&1){
			res*=x;
			res%=mod;
		}
		x*=x;
		x%=mod;
		k>>=1;
	}
	return res;
}
ll fact[200001];
ll comb(ll a,ll b){
	if(b>a)return 0;
	ll inv1=qp(fact[b],mod-2);
	ll inv2=qp(fact[a-b],mod-2);
	return ((1ll*fact[a]*inv1)%mod)*inv2%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fact[0]=1;
	for(int i=1;i<=200000;i++){
		fact[i]=1ll*i*fact[i-1]%mod;
	}
	int t;cin>>t;
	while(t--){
		int xa,xb,ya,yb;
		cin>>xa>>ya>>xb>>yb;
		if(ya==0||yb==0||(ll)ya*yb<0){
			cout<<"0\n";continue;
		}
		int len=xb-xa;
		if(len<0){
			cout<<"0\n";continue;
		}
		int c1=len+abs(yb-ya);
		int c2=len+abs(yb+ya);
		if(c1&1){
			cout<<"0\n";continue;
		}
		c1>>=1;c2>>=1;
		//C(len,c1)
		cout<<(comb(len,c1)-comb(len,c2)+mod)%mod<<'\n';
	}
	return 0;
}
