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
void exgcd(ll &x,ll &y,ll a,ll b){
	if(b==0){
		x=1;y=0;
		return;
	}
	ll x1,y1;
	exgcd(x1,y1,b,a%b);
	x=y1;y=x1-(a/b)*y1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>a(n+1),b(n+1);
	vector<ll>m(n+1,1);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		m[0]*=a[i];
	}
	for(int i=1;i<=n;i++)
		m[i]=m[0]/a[i];
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll x,y;
		exgcd(x,y,m[i],a[i]);
		x%=a[i],x+=a[i],x%=a[i];
		ans+=(__int128)m[i]*b[i]%m[0]*x%m[0];
		ans%=m[0];
	}
	cout<<ans;
	return 0;
}
