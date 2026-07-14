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
	string s;
	cin>>s;s=' '+s;
	vector<int>a(n+1,0);
	for(int i=2;i<=n;i++)
		a[i]=a[i-1]+(s[i]==s[i-1]);
	for(int i=1;i<=q;i++){
		int l,r,k;
		cin>>l>>r>>k;
		if((a[r]-a[l]+1)/2<=k)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
