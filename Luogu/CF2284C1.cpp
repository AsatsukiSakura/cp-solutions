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
vector<int>primes;
vector<int>isprime(200001,true);
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=*lower_bound(primes.begin(),primes.end(),a[i]);
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=2;i<=200000;i++){
		if(isprime[i]){
			primes.push_back(i);
		}
		for(int p:primes){
			if(i*p>200000)break;
			isprime[i*p]=false;
			if(i%p==0)break;
		}
	}
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
