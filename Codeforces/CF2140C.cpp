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
const ll inf=0x3f3f3f3f3f3f;
const double eps=1e-8;
void solve(){
	int n;
	cin>>n;
	vector<ll>a(n+1,0);
	ll s=0;
	for(int i=1,c=1;i<=n;i++,c*=-1){
		cin>>a[i];
		s+=c*a[i];
	}
	ll g=((n+1)/2-1)*2;
	ll mn=inf,mx=-inf;
	for(int i=1;i<=n;i++){
		if(i&1){
			g=max(g,mx-(2*a[i]-i));
			mn=min(mn,2*a[i]+i);
		}
		else{
			mx=max(mx,2*a[i]-i);
			g=max(g,2*a[i]+i-mn);
		}
	}
	cout<<s+g<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
