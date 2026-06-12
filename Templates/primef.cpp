#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
vector<ll>primes;
void init(int n){
	vector<bool>isprime(n+1,true);
	for(int i=2;i<=n;i++){
		if(isprime[i])
			primes.push_back(i);
		for(int p:primes){
			if(i*p>n) break;
			isprime[i*p]=false;
			if(i%p==0) break;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init(1e9);
	freopen("prime.in","r",stdin);
	freopen("prime.txt","w",stdout);
	while(1){
		ll x;
		cin>>x;
		if(x<=1)break;
		cout<<x<<'=';
		for(ll p:primes){
			if(p*p>x)break;
			while(x%p==0){				
				cout<<p<<'*';
				x/=p;
			}
		}
		if(x!=1)cout<<x;
		cout<<endl;
	}
	return 0;
}
