#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using lll=__int128_t;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
lll qp(lll b,ll p,ll m){
	lll r=1;
	while(p){
		if(p&1){
			r=r*b%m;
		}	
		b=b*b%m;
		p>>=1;
	}
	return r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin>>n;
	ll d=n-1;
	while(!(d&1))d>>=1;
	bool prime=true;
	for(int i:{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61}){
		if(i==n){
			prime=true;
			break;
		}
		lll r=qp(i,d,n);
		for(ll p=d;p<=n-1;p*=2){
			if(r!=1 && r!=n-1&&r*r%n==1){
				break;
			}
			r=r*r%n;
		}
		if(r!=1){
			prime=false;
			break;
		}
	}
	cout<<prime;
	return 0;
}
