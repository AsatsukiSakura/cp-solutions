#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	vector<int>primes;
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
	for(int i=1;i<=q;i++){
		int t;
		cin>>t;
		cout<<primes[t-1]<<'\n';
	}
	return 0;
}
