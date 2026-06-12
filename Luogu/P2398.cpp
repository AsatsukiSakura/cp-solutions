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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>phi(n+1,0),primes;
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!phi[i]){
			phi[i]=i-1;
			primes.push_back(i);
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
	ll ans=0;
	cout<<phi[4];
	for(int i=1;i<=n;i++){
		ans+=1ll*(n/i)*(n/i)*phi[i];
	}
	cout<<ans;
	return 0;
}
