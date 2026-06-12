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
inline ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1){
			r*=b;
			r%=mod;
		}
		b*=b;
		b%=mod;
	}
	return r;
}
vector<ll>fact(2001,1);
ll comb(int x,int k){
	if(k<0||k>x)return 0;
	ll r=fact[x]*qp(fact[k],mod-2)%mod;
	r=r*qp(fact[x-k],mod-2)%mod;
	return r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int>a(m+1);
	for(int i=1;i<=m;i++){
		cin>>a[m];
	}
	for(int i=2;i<=2000;i++){
		fact[i]=i*fact[i-1]%mod;
	}
	ll ans=0;
	for(int i=0,c=1;i<=n-1;i++){
		ll tmp=comb(n,i);
		for(int j=1;j<=m;j++){
			tmp*=comb(a[j]+n-i-1,n-i-1);
			tmp%=mod;
		}
		ans+=c*tmp;
		ans%=mod,ans+=mod,ans%=mod;
		c*=-1;
	}
	cout<<ans;
	return 0;
}
