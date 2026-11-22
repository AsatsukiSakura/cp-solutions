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
#define int long long
void solve(){
	int n;
	cin>>n;
	
	/*
	最大值最小化。。。
	考虑对最大的距离k
	找到最贪心构造。
	
	*/
	vector<int>a(n+1);
	vector<int>l(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)cin>>l[i];
	ll lf=0,rt=1e9;
	auto check=[&](int k){
		int mn=a[1]-k,mx=a[1]+k;
		for(int i=2;i<=n;i++){
			int hasl=(mx-l[i]>=a[i]-k);
			int hasr=(mn+l[i]<=a[i]+k);
			if((hasl+hasr)==0)return false;
			mn=hasl?a[i]-k:max(a[i]-k,mn+l[i]);
			mx=hasr?a[i]+k:min(a[i]+k,mx-l[i]);
		}
		return true;
	};
	while(lf<=rt){
		ll mid=(lf+rt)/2;
		if(check(mid))rt=mid-1;
		else lf=mid+1;
	}
	cout<<lf<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
//1000000000000000000 200000000000000001 1000000000000000000 1000000000000000000
