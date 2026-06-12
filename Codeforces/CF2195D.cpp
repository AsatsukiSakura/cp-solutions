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
	vector<ll>f(n+1),a(n+1);
	for(int i=1;i<=n;i++)
		cin>>f[i];
	ll sum=0;
	for(int i=2;i<=n-1;i++){
		a[i]=(f[i-1]+f[i+1]-2ll*f[i])/2ll;
		sum+=a[i];
	}
	a[n]=f[1];
	for(int i=2;i<=n-1;i++){
		a[n]-=a[i]*(i-1);
	}
	a[n]/=n-1;
	a[1]=f[n];
	for(int i=n-1;i>=2;i--){
		a[1]-=a[i]*(n-i);
	}
	a[1]/=n-1;
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<'\n';
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
