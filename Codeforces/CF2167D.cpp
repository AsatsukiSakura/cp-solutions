#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
vector<int>primes;
vector<bool>isprime(1e5,true);
void init(){
	for(int i=2;i<=1e5;i++){
		if(isprime[i])primes.push_back(i);
		for(int p:primes){
			if(i*p>1e5)break;
			isprime[i*p]=false;
			if(i%p==0)break;
		}
	}
}
void solve(){
	int n;
	ll g;
	cin>>n;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)g=a[1];
		else g=gcd(a[i],g);
	}
	for(int p:primes){
		if(g%p!=0){
			cout<<p<<endl;
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	init();
	while(t--)solve();
	return 0;
}
