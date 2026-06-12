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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	vector<int>phi(n+1,0);
	vector<int>primes;
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!phi[i]){
			primes.push_back(i);
			phi[i]=i-1;
		}
		for(int p:primes){
			if(i*p>n)break;
			if(i%p==0){
				phi[i*p]=phi[i]*p;
				break;
			}
			phi[i*p]=phi[i]*phi[p];
		}
	}
	vector<vector<int>>fac(n+1);
	for(int i=1;i<=n/2;i++){
		for(int j=2*i;j<=n;j+=i){
			fac[j].push_back(i);
		}
	}
	ll ans=0;
	for(int c=1;c<=n-2;c++){
		for(int d:fac[n-c]){
			ans+=1ll*c*d/gcd(c,d)*phi[(n-c)/d]%mod;
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
