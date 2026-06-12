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
	int n,q;
	cin>>n>>q;
	vector<int>a(n+1),b(n+1),m(n+1);
	vector<ll>s(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	m[n]=max(a[n],b[n]);
	for(int i=n-1;i>=1;i--){
		m[i]=max({m[i+1],a[i],b[i]});
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+m[i];
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		cout<<s[r]-s[l-1]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
