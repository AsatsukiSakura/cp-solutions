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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll lt=1,rt=1e16;
	vector<ll>pre(n+1,0),suf(n+2,0);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]+pre[i-1];
	}
	for(int i=n;i>=1;i--){
		suf[i]=a[i]+suf[i+1];
	}
	auto check=[&](ll x)->bool{
		if(x>=pre[n])return true;
		int i=1,j=n;
		while(i<=n&&suf[i]>x)i++;i--;
		while(j>=1&&pre[j]>x)j--;j++;
		if(pre[i]+suf[j]>x)return false;
		else return true;
	};
	while(lt<=rt){
		ll mid=(lt+rt)/2;
		if(check(mid))rt=mid-1;
		else lt=mid+1;
	}
	cout<<lt<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
