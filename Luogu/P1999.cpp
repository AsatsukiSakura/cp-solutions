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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b;
	cin>>a>>b;
	ll fact[100001];
	fact[0]=1;
	for(int i=1;i<=a;i++){
		fact[i]=i*fact[i-1]%mod;
	}
	cout<<(a>=b?1ll*fact[a]*qp(fact[a-b],mod-2)%mod*qp(fact[b],mod-2)%mod*qp(2,a-b)%mod:0);
	return 0;
}
