#include<bits/stdc++.h>
using ll=unsigned long long;
using namespace std;
const ll mod=1ULL<<32; 
ll n,w[32],a[500005];
ll tol(int x){
	ll ans= 1ULL*(x*x)%mod*((n-x)*(n-x)%mod)+1ULL*(n*n-x*x)%mod*((n*n-(n-x)*(n-x))%mod);
	ans%=mod;
	return ans;
}
int main(){
	
	ll ans=0;
	cin>>n;
	memset(w,0,sizeof(w));
	for(int i=1;i<=n;i++){
		cin>>a[i];int j=0;
		while(a[i]){
			w[j]+=(a[i]&1);
			a[i]>>=1;
			j++;
		}
	}
	for(int i=0;i<=32;i++){
		ans+=(1ULL<<i)%mod*(tol(w[i])%mod);
		ans%=mod;
	}
	cout<<ans%mod;
} 

