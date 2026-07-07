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
	int n;
	ll k;
	cin>>n>>k;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<ll>c;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			if(i!=1)c.push_back(cnt);
			cnt=1;
		}
		else cnt++;
	}
	c.push_back(cnt);
	sort(c.begin(),c.end());
	int m=c.size()-1;
	vector<ll>suf=c;
	for(int i=m-1;i>=0;i--){
		suf[i]=suf[i+1]+c[i];
	}
	int ans=0;
	for(int i=0;i<=m;i++){
		if(i>0 && c[i]==c[i-1])continue;
		if((k-suf[i])%(m+1-i)==0){
			ll x=(k-suf[i])/(m+1-i);
			if(c[i]+x>=1)ans++;
		}
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
