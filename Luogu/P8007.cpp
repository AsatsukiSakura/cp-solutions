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
	string s;
	cin>>n>>s;
	if(n&1){cout<<0;return 0;}
		int l=0,r=0;
	for(char c:s){
		l+=(c=='(');
		r+=(c==')');
	}
	ll f[100001];
	f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]*i%mod;
	}
	cout<<f[n-l-r]*qp(f[n/2-l],mod-2)%mod*qp(f[n/2-r],mod-2)%mod;
	return 0;
}
