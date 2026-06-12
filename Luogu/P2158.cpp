#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	vector<int>primes,phi(n+1,0);phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!phi[i]){
			primes.push_back(i);
			phi[i]=i-1;
		}
		for(int p:primes){
			if(i*p>n) break;
			if(i%p==0){
				phi[i*p]=p*phi[i];
				break;
			}
			phi[i*p]=phi[p]*phi[i];
		}
	}
	ll ans=0;
	for(int i=1;i<=n-1;i++){
		ans+=2*phi[i];
	}
	cout<<ans+min(1,n-1);
	return 0;
}
