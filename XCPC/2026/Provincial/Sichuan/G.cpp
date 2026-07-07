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
	ll n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	vector<ll>s(n+1,0);
	map<ll,int>m[2];
	m[0][0]=1;
	for(int i=1,c=1;i<=n;i++,c*=-1){
		cin>>a[i];
		s[i]=s[i-1]+c*a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=m[i&1][k-s[n]+s[i]];
		ans+=m[1^(i&1)][k+s[n]-s[i]];
		m[i&1][s[i]]++;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
