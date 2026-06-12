#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
vector<int>phi(1e7+1,0);
vector<int>primes;
void init(){
	phi[1]=1;
	for(int i=2;i<=1e7;i++){
		if(!phi[i]){
			phi[i]=i-1;
			primes.push_back(i);
		}
		for(int p:primes){
			if(i*p>1e7)break;
			if(i%p==0){
				phi[i*p]=p*phi[i];
				break;
			}
			phi[i*p]=phi[p]*phi[i];
		}
	}
}
ll qp(ll a,int b,int p){
	ll res=1;
	while(b){
		if(b&1){
			res*=a;
			res%=p;
		}
		a*=a;
		a%=p;
		b>>=1;
	}
	return res;
}
int calc(int p){
	if(p==1)return 0;
	else return qp(2,calc(phi[p])+phi[p],p);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int t;cin>>t;
	while(t--){
		int p;
		cin>>p;
		cout<<calc(p)<<endl;
	}
	return 0;
}
