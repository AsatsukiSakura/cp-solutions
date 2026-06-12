#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=143;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1){
			r=r*b%mod;
		}
		b=b*b%mod;
		p>>=1;
	}
	return r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<qp(71,121);
	int n,k;
	cin>>n>>k;
	cout<<qp(2,1ll*n*k);
	return 0;
}
