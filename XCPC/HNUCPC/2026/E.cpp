#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
const ll mod=1e9+7;
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1){
			r=(r*b)%mod;
		}
		b=(b*b)%mod;
		p>>=1;
	}
	return r;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		cout<<qp(m+1,n)<<'\n';
	}

} 
