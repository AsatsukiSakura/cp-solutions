#include<bits/stdc++.h>
#define ll long long
const ll mod=1e9+7;
using namespace std;
vector<bool>isprime(1e6+5,true);
vector<ll>prime;
void init(){
	isprime[0]=false; 
	isprime[1]=false;
	for (int i=2;i<=1e6;i++){
		if(isprime[i]) 
			prime.push_back(i);
		for(ll j:prime){
			if(i*j>1e6) break;
			isprime[i*j]=false;
			if(i%j==0) break;
		}
	}
}
void solve(){
	ll n,pct,t=1,nn;
	cin>>n; nn=n;
	for(ll i:prime){
		if(i*i*i>nn)break;
		pct=0;
		while(nn%i==0){
			nn/=i;pct++;
		}
		t*=pow(i,pct/2);
		t%=mod;
	}
	ll sq=(ll)sqrt(nn);
	if(sq*sq==nn){
		t*=sq;t%=mod;
	}
	cout<<(((n%mod)*(n%mod))%mod+t)%mod<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int t;cin>>t;
	while(t--)	solve(); 
	return 0;
}
