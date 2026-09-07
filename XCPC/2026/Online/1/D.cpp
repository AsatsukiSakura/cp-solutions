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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	multiset<int>p;
	for(int i=1;i<=n;i++){
		int x;cin>>x;p.insert(x);
	}
	int a=0,b=0,ans=1;
	for(int i=1;i<=n;i++){
		if(*p.begin()<a){cout<<"0\n";return 0;}
		if(a==b){
			if(p.find(a)==p.end()){cout<<"0\n";return 0;}
			p.erase(p.find(a));
			b++;
			ans=2*ans%mod;
		}
		else{
			if(p.find(a)!=p.end()){
				p.erase(p.find(a));
				b++;
			}
			else {
				if(p.find(b)==p.end()){cout<<"0\n";return 0;}
				p.erase(p.find(b));
				a++;
			}
		}
	}
	cout<<ans;
	return 0;
}
