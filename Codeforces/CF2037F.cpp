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
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>h(n+1),x(n+1);
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)cin>>x[i];
	ll l=1,r=1e9;
	auto check=[&](ll mid){
		vector<pii>ev;
		for(int i=1;i<=n;i++){
			int dis=m-(h[i]+mid-1)/mid;
			if(dis<0)continue;
			ev.push_back({x[i]-dis,1});
			ev.push_back({x[i]+dis+1,-1});
		}
		sort(ev.begin(),ev.end());
		int cnt=0;
		for(pii p:ev){
			cnt+=p.second;
			if(cnt>=k)return true;
		}
		return false;
	};
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<(l>1e9?-1:l)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
