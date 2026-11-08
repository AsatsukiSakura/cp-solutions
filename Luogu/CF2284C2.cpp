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
	int a,b;
	cin>>a>>b;
	if(a==b){
		cout<<0<<'\n';
		return;
	}
	if(gcd(a,b)==1){
		cout<<1<<'\n';
		cout<<b-a<<'\n';
		return;
	}
	auto cp=[&](int x){
		for(int p:primes){
			if(p*p>x) return true;
			if(x%p==0)	return false;
		}return true;
	};
	if(a+300<=b){
		int tar;
		for(int i=b-1;i>=a+1;i--){
			if(cp(i)){
				tar=i;
				break;
			}
		}
		cout<<2<<'\n'<<tar-a<<' '<<b-tar<<'\n';
		return;
	}
	vector<int>p(500,0);
	queue<int>q;
	q.push(a);
	while(!q.empty()){
		int st=q.front();
		q.pop();
		if(gcd(st,b)==1){
			p[b-a]=st;
			break;
		}
		for(int i=st+1;i<=min(b-1,st+300);i++){
			if(p[i-a]==0&&gcd(st,i)==1){
				p[i-a]=st;
				q.push(i);
			}
		}
	}
	vector<int>ans;
	int u=b;
	while(u!=a){
		ans.push_back(u-p[u-a]);
		u=p[u-a];
	}
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(int x:ans)cout<<x<<' ';
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
	while(t--)
		solve();
	return 0;
}
