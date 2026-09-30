#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
void solve(){
	int n;
	cin>>n;
	vector<pll>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a.begin()+1,a.end());
	ll l=1,r=1e9+100;
	auto check=[&](ll x)->bool{
		ll z=0;
		ll nd=1;
		for(int i=n;i>=1;i--){
			if(a[i].first>=x){
				z+=a[i].second;
			}else{
				if(x-a[i].first>=56)return false;
				if(((ll)2e14)/(1ll<<(x-a[i].first-1))<nd)return false;
				nd<<=(x-a[i].first-1);
				if(a[i].first==0){
					x=0;
					z+=a[i].second;
					break;
				}
				if(nd>=a[i].second)
					nd+=(nd-a[i].second);
				else 
					z+=(a[i].second-nd);
				x=a[i].first;
			}
		}
		if(x>0){
			if(x>=56)return false;
			if(((ll)2e14)/(1ll<<(x-1))<nd)return false;
			nd<<=(x-1);
		}
		return z>=nd;
	};
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<max(r,a[n].first)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
