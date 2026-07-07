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
vector<ll>getp(ll x){
	vector<ll>res;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			res.push_back(i);
			while(x%i==0) x/=i;
		}
	}
	if(x>1)res.push_back(x);
	return res;
}
void solve(){
	ll n;
	cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	ll g=a[0];
	for(int i=1;i<n;i++)g=gcd(g,a[i]);
	for(int i=0;i<n;i++)a[i]/=g;
	set<ll>v;
	for(ll p:getp(a[0]))v.insert(p);
	for(ll p:getp(a[1]))v.insert(p);
	if(v.size()==0){cout<<"NO\n";return;}
	for(ll p:v){
		int cnt=0;
		vector<ll>b;
		for(int i=0;i<n;i++){
			if(a[i]%p!=0)	
				b.push_back(a[i]);
			else cnt++;
		}
		if(cnt>=n-1){cout<<"YES\n";return;}
		set<ll>vv;
		for(ll q:getp(b[0]))vv.insert(q);
		for(ll q:getp(b[1]))vv.insert(q);
		if(vv.size()==0) continue;
		for(ll q:vv){
			int cntt=cnt;
			for(ll x:b){
				if(x%q==0)cntt++;
			}
			if(cntt>=n-1){cout<<"YES\n";return;}
		}
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
