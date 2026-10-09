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
	ll n,k;
	cin>>n>>k;
	vector<ll>a(n+1,0);
	auto b=a,c=a;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	ll r=4e18,l=-r;
	auto check=[&](const ll &x){
		ll cost=0;
		for(int i=1;i<=n;i++){
			ll s=a[i]+b[i]+c[i];
			if(s>=x)continue;
			if(a[i]<=b[i] && b[i]<=c[i]){
				if(a[i]==b[i]&&b[i]==c[i])return false;
				cost+=x-s+min((b[i]-a[i]),(c[i]-b[i]))*2+2;}
			else
				cost+=x-s;
			if(cost>k)return false;
		}
		return cost<=k;
		
	};
	while(l<=r){
		ll mid=l+(r-l)/2;
		//debug(mid);
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
