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
void solve(){
	ll p,q;
	cin>>p>>q;
	ll t=2*p+4*q+1;
	bool f=false;
	for(ll d=3;d*d<=t;d+=2) {
		if(t%d==0) {
			ll xx=d;
			ll yy=t/d;
			ll n=(xx-1)/2;
			ll m=(yy-1)/2;
			if(n>=1&&m>=1&&abs(n-m)<=p){
				cout<<n<<' '<<m<<'\n';
				f=true;
				break;
			}
		}
	}
	if(!f){
		cout<<-1<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
