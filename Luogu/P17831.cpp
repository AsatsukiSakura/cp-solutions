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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	ll nd=0;
	int ans=1;
	for(int i=1,j=1;i<=n;){
		while(nd>m){
			nd-=a[i]-a[j++];
		}
		if(nd<=m)ans=max(i-j+1,ans);
		if(i<n)nd+=1ll*(i-j+1)*(a[i+1]-a[i]);
		i++;
	}
	cout<<ans<<'\n';
	return 0;
}
