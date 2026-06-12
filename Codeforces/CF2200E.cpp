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
vector<int>ispn(1e6+1,0);
void init(){
	iota(ispn.begin(),ispn.end(),0);
	for(int i=2;i<=1e6;i++){
		if(ispn[i]){
			primes.push_back(i);
		}
		for(int p:primes){
			if(i*p>1e6)break;
			ispn[i*p]=0;
			if(i%p==0)break;
		}
	}
	for(int p:primes){
		ll x=p;
		while(x<=1e6){
			ispn[x]=p;
			x*=p;
		}
	}
}
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool b=false;
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1])b=true;
	}
	if(!b){cout<<"Bob\n";return;}
	for(int i=1;i<=n;i++){
		a[i]=ispn[a[i]];
	}
	if(*min_element(a.begin()+1,a.end())==0){
		cout<<"Alice\n";return;
	}
	b=false;
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1])b=true;
	}
	cout<<(b?"Alice\n":"Bob\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	debug(ispn[8192]),debug(ispn[677]);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
