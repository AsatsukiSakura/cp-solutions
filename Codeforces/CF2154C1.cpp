#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
vector<bool>isprime(1000+5,true);
vector<int>prime;
void init(){
	isprime[0]=false; 
	isprime[1]=false;
	for (int i=2;i<=1000;i++){
		if(isprime[i]) 
			prime.push_back(i);
		for(ll j:prime){
			if(i*j>1000) break;
			isprime[i*j]=false;
			if(i%j==0) break;
		}
	}
}
void solve(){
	int n,mn=2;
	cin>>n;
	vector<int>a(n+1),b(n+1);
	set<int>sprimes,sprimes1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		int ii=a[i];
		for(int p:prime){
			if(ii%p==0){
				if(sprimes.count(p)){
					mn=min(mn,0);
				}
				if(sprimes1.count(p)){
					mn=min(mn,1);
				}
				sprimes.insert(p);
				while(ii%p==0)ii/=p;
			}
		}
		if(ii!=1){
			if(sprimes.count(ii))
				mn=min(mn,0);
			if(sprimes1.count(ii))
				mn=min(mn,1);
			sprimes.insert(ii);
		}
		ii=a[i]+1;
		for(int p:prime){
			if(ii%p==0){
				if(sprimes.count(p)){
					mn=min(mn,1);
				}
				sprimes1.insert(p);
				while(ii%p==0)ii/=p;
			}
		}
		if(ii!=1){
			if(sprimes.count(ii))
				mn=min(mn,1);
			sprimes1.insert(ii);
		}
	}
	cout<<mn<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	init();
	while(t--)solve();
	return 0;
}
