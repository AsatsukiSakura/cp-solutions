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
	int n,k;
	string s;
	cin>>n>>k>>s;
	s=' '+s;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+s[i]-'0';
	int ans=0;
	for(int i=1;i<=n;i+=k)
		if(a[i+k-1]-a[i-1]==k)
			ans++;
	cout<<ans<<'\n';
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
