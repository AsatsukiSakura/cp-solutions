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
	int n;
	cin>>n;
	vector<int>a(n+1),b(n+1),c(n+1);
	ll ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	int cnt1=0,cnt2=0;
	for(int s=0;s<=n-1;s++){
		bool q=true;
		for(int i=1;i<=n;i++){
			if(a[(i+s-1)%n+1]>=b[i]){
				q=false;break;
			}
		}
		if(q)cnt1++;
	}
	for(int s=0;s<=n-1;s++){
		bool q=true;
		for(int i=1;i<=n;i++){
			if(b[(i+s-1)%n+1]>=c[i]){
				q=false;break;
			}
		}
		if(q)cnt2++;
	}
	cout<<1ll*n*cnt1*cnt2<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
