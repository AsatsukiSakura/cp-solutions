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
	ll a,b,c,m;
	cin>>a>>b>>c>>m;
	ll aa=0,bb=0,cc=0;
	aa+=6ll*(m/a),bb+=6ll*(m/b),cc+=6ll*(m/c);
	aa-=3ll*(m/lcm(a,b)),aa-=3ll*(m/lcm(a,c));
	bb-=3ll*(m/lcm(a,b)),bb-=3ll*(m/lcm(b,c));
	cc-=3ll*(m/lcm(c,b)),cc-=3ll*(m/lcm(a,c));
	aa+=2ll*(m/lcm(a,lcm(b,c)));
	bb+=2ll*(m/lcm(a,lcm(b,c)));
	cc+=2ll*(m/lcm(a,lcm(b,c)));
	cout<<aa<<' '<<bb<<' '<<cc<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
