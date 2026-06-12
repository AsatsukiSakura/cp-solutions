#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
int cnt=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int>primes;
	vector<int>isprime(2000001,true);
	for(int i=2;i<=2000000;i++){
		if(isprime[i]){
			primes.push_back(i);
			cnt++;
		}
		for(int p:primes){
			cnt++;
			if(i*p>2000000)break;
			isprime[i*p]=false;
			if(i%p==0)break;
		}
	}
	cout<<cnt<<endl;
	int n,mod;
	cin>>n>>mod;
	ll ans=1;
	for(ll p:primes){
		int w=0;
		for(ll i=p;i<=2*n;i*=p){
			w+=(2*n/i-n/i-(n+1)/i);
			cnt++;
		}
		//if(w) debug(p),debug(w)<<endl;
		while(w){
			if(w&1){
				ans=ans*p%mod;
				cnt++;
			}
			p=p*p%mod;
			cnt++;
			w>>=1;
		}
	}
	cout<<ans<<' '<<cnt;
	return 0;
}
