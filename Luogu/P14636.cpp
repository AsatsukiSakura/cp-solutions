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
vector<vector<ll>>CC(5001,vector<ll>(5001,0));
vector<ll>p2(5001,1);
void init(){
	for(int i=1;i<=5000;i++){
		p2[i]=2*p2[i-1]%mod;
	}
	for(int i=0;i<=5000;i++){
		CC[i][0]=1;
		for(int j=1;j<=i;j++)
			CC[i][j]=(CC[i-1][j-1]+CC[i-1][j])%mod;
	}
}
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1)r=r*b%mod;
		b=b*b%mod;
		p>>=1;
	}
	return r;
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	ll ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end(),greater<int>());
	auto C=[](ll n,ll k){
		if(k>n || k<0)return 0ll;
		else return CC[n][k];
	};
	for(int i=1;i<=n-1;i++){
		for(int j=i+1,k=n+1;2*a[j]>a[i]&&j<=n;j++){
			if(a[i]==a[j]) continue;
			while(a[j]+a[k-1]<a[i] && k-1>j)k--;
			ans+=C(j-2,m-i-1)*p2[n-k+1]%mod;
			ans%=mod;
		}
	}
	cout<<(p2[n]-ans%mod+mod)%mod<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
