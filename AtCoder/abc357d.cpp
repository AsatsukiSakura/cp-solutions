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
	ll x=n;
	int d=0;
	while(x){x/=10;d++;}
	//(1+10^d+10^(2d)+...+10^((n-1)d))*n
	auto qp=[](ll b,ll p){
		ll r=1;
		while(p){
			if(p&1)r=r*b%mod;
			b=b*b%mod;
			p>>=1;
		}
		return r;
	};
	ll ans=n%mod*(qp(qp(10,d),n)+mod-1)%mod*qp(qp(10,d)+mod-1,mod-2)%mod;
	cout<<ans;
	return 0;
}
