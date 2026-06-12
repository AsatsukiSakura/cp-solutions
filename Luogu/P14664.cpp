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
void solve(){
	int a,b,n;
	cin>>n;
	ll ans=0;
	int c=0;
	for(int i=log2(n);i>=0;i--){
		if(n&(1<<i)){
			ans+=(1<<i);
			c++;
		}
		else if(c>1){
			ans+=(1<<i)<<1;	
		}
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
