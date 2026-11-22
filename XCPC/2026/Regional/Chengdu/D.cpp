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
	ll a,b,ha,hb;
	cin>>a>>b>>ha>>hb;
	//ceil(ha/b)-4>=ceil(hb/a)
	ll at=(ha+b-1)/b;
	ll bt=(hb+a-1)/a;
	if(at-4>=bt)
		cout<<"YES\n";
	else 
		cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
//1000000000000000000 200000000000000001 1000000000000000000 1000000000000000000
