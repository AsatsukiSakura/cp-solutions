#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
vector<int>phi;
vector<ll>phis;
vector<int>primes;
void init(int n){
	phi.resize(n+1);
	phis.resize(n+1);
	phi[1]=1;
	vector<bool>isprime(n+1,true);
	for(int i=2;i<=n;i++){
		if(isprime[i]){
			phi[i]=i-1;
			primes.push_back(i);
		}
		for(int p:primes){
			if(i*p>n)break;
			isprime[i*p]=false;
			if(i%p==0){
				phi[i*p]=p*phi[i];
				break;
			}
			phi[i*p]=phi[p]*phi[i];
		}
	}
	phis[1]=1;
	for(int i=2;i<=n;i++){
		phis[i]=phis[i-1]+phi[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	init(n);
	ll ans=0;
	for(int p:primes){
		if(p>n)	break;
		ans+=2*phis[n/p];
		ans--;
	}
	cout<<ans;
	return 0;
}
