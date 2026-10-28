#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
#define int long long
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int zc=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			zc++;
			ans+=i-zc;
		}
	}
	string s;
	cin>>s;
	s=' '+s;
	int l=1,r=n;
	cout<<ans<<' ';
	for(int i=1;i<=n;i++){
		while(l<=n&&a[l]==0)l++,zc--;
		while(r>=1&&a[r]==1)r--;
		if(l<=r){
			if(s[i]=='1'){
				ans-=zc;
				l++;
			}
			else{
				ans-=r-l+1-zc;
				r--;
				zc--;
			}
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
