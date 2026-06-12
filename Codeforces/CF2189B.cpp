#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
#define int long long
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
void solve(){
	int n;
	ll x;
	cin>>n>>x;
	vector<int>a(n+1),b(n+1),c(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	ll p=0;
	for(int i=1;i<=n;i++){
		p+=1ll*(b[i]-1)*a[i];
	}
	if(p>=x){
		cout<<"0\n";
		return;
	}
	pii idx={0,-inf*inf};
	for(int i=1;i<=n;i++){
		ll val=1ll*b[i]*a[i]-c[i];
		if(val>idx.second)
			idx={i,val};
	}
	if(idx.second<=0){
		cout<<"-1\n";
		return;
	}
	cout<<(x-p+idx.second-1)/idx.second<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
