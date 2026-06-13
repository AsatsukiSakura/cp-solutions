#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll k=n*(n-1)/2-m;
		int ans1=(1.0+sqrt(1+8*k))/2.0;
		cout<<ans1<<' ';
		ll l=1,r=n;
		while(l<=r){//分成mid快
			ll mid=(l+r)/2;
			ll sz=n/mid;
			ll ans2=1ll*(mid-n%mid)*sz*(sz-1)/2+1ll*(n%mid)*(sz+1)*sz/2;
			if(m<ans2)l=mid+1;
			else r=mid-1;
		}
		cout<<l<<endl;
	}
	return 0;
}
/*
n-1+n-2+n-3+...1=
*/