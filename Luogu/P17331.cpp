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
	int n,k;
	cin>>n>>k;
	int cnt=0;
	multiset<int>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt+=(x==k);
		s.insert(x);
	}
	ll ans=0;
	if(k==1&&cnt!=0){cout<<"-1\n";return ;}
	for(int i=1;i<k;i++){
		auto it=s.lower_bound(i);
		if(it==s.end()){cout<<"-1\n";return ;}
		ans+=(*it)-i;
		if(*it==k)cnt--;		
		s.erase(it);
	}
	cout<<ans+cnt<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
