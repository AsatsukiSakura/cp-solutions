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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	ll l=1,r=4e14;
	auto check=[&](ll tme){
		vector<int>f(n+1,0),g(n+1,0);
		priority_queue<int>pq;
		ll sum=0;
		for(int i=1;i<=n;i++){
			pq.push(a[i]);
			sum+=a[i];
			if(sum>tme){
				sum-=pq.top();
				pq.pop();
			}
			f[i]=pq.size();
		}
		while(!pq.empty())pq.pop();
		sum=0;
		for(int i=n;i>=1;i--){
			pq.push(a[i]);
			sum+=a[i];
			if(sum>tme){
				sum-=pq.top();
				pq.pop();
			}
			g[i]=pq.size();
		}
		for(int i=0;i<=n-1;i++)
			if(f[i]+g[i+1]>=k)return 1;
		return 0;
	};
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
