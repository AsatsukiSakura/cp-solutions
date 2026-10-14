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
	int n;
	cin>>n;
	vector<pii>a(n+1);
	vector<vector<int>>fac(n+1);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			fac[j].push_back(i);
	for(int i=1;i<=n;i++)
		cin>>a[i].first,a[i].second=i;
	vector<pii>mx(n+1,{0,0});
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			mx[i]=max(mx[i],a[j]);
	auto qp=[](ll b,ll p){
		ll r=1;
		while(p){
			if(p&1)
				r=r*b%mod;
			p>>=1;
			b=b*b%mod;
		}
		return r;
	};
	ll ans=0;
	auto mv=mx;
	sort(mv.begin()+1,mv.end());
	for(int i=1;i<=n;i++){
		int c=0;
		int e=mv.end()-upper_bound(mv.begin()+1,mv.end(),mx[i]);
		for(int d:fac[i])
			if(mx[d]<=a[i])
				c++;
		ans+=1ll*a[i].first*(qp(2,c)+mod-1)%mod*qp(2,n-c-e)%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
	
}


