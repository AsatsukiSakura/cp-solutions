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
	int n,x;
	cin>>n>>x;
	int l=1,r=1e9;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	auto check=[&](int dis){
		int cur=-inf;
		int y=0;
		for(int i=1;i<=n;i++){
			if(a[i]-cur>dis&&(i==n||a[i+1]-a[i]>dis)){
				y++;
				cur=a[i]+dis;
			}
			else cur=a[i];
		}
		return y<=x;
	};
	while(l<=r){
		int mid=l+(r-l)/2;
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
