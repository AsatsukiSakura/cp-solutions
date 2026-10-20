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
	int n;
	cin>>n;
	for(int i=0;i<=9;i++){
		int d=9;
		int tmp=n-i;
		for(int j=0;j<=9;j++){
			d=min(d,(17-tmp%10)%10);
			tmp/=10;
		}
		if(d<=i){
			cout<<i<<'\n';
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
