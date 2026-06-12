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
	int n,h,k;
	cin>>n>>h>>k;
	vector<int>a(n+1),mn(n+1,inf);
	vector<ll>sum(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn[i]=min(mn[i-1],a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	int r=h/sum[n];
	ll t=1ll*r*(n+k);
	h%=sum[n];
	vector<int>mx(n+2,0);
	for(int i=n;i>=1;i--){
		mx[i]=max(a[i],mx[i+1]);
	}
	if(h==0)t-=k;
	for(int i=0;i<=n;i++){
		if(sum[i]+max(0,mx[i+1]-mn[i])>=h){
			t+=i;break;
		}
	}
	cout<<t<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
