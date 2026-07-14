#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1){
			r=(r*b)%mod;
		}
		b=(b*b)%mod;
		p>>=1;
	}
	return r;
}
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int n1c=lower_bound(a.begin()+1,a.end(),1)-a.begin()-1;
	int p1c=0,cnt=0;
	for(int i=n1c+1;i<=n;i++){
		if(i==n1c+1||a[i]!=a[i-1])cnt++;
		if(i!=n)p1c+=(a[i+1]==a[i]+1);
	}
	int len=n-n1c;
	if(n1c==0) cout<<qp(2,len-cnt);
	else cout<<1ll*qp(2,len-cnt+n1c-1)*(1+p1c)%mod;
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
