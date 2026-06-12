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
ll qp(ll b,ll p){
	ll r=1;
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
const int _=1e6;
ll fact[_+5],inv[_+5],d[_+5];
void solve(){
	int n,m;
	cin>>n>>m;
	//C(n,m)*D(n-m)
	if(m>n) cout<<"0\n";
	else cout<<fact[n]*inv[m]%mod*inv[n-m]%mod*d[n-m]%mod<<'\n';
}
void init(){
	fact[0]=1;
	for(int i=1;i<=_;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	inv[_]=qp(fact[_],mod-2);
	for(int i=_-1;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
	d[0]=1;d[1]=0;
	for(int i=2;i<=_;i++){
		d[i]=(d[i-2]+d[i-1])*(i-1)%mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
