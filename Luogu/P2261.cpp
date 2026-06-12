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
	int n,k;
	cin>>n>>k;
	int i=1;
	ll ans=1ll*n*k;
	while(i<=n&&i<=k){
		int r=k/(k/i);
		if(r<=n)ans-=1ll*(r-i+1)*(k/i)*(i+r)/2ll;
		else ans-=1ll*(n-i+1)*(k/i)*(i+n)/2ll;
		i=r+1;
	}
	cout<<ans;
	return 0;
}
