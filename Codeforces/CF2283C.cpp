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
	int x=0;
	for(int i=1;i<=n;i++){
		x^=i;
	}
	int d=__lg(n);
	debug(d);
	vector<int>a(n+1,0);
	for(int i=d+1;i>=1;i--){
		if((x>>i)&1)continue;
		else{
			a[1<<(i-1)]=1;
			x^=(1<<(i-1));
			x^=(1<<i);
		}
	}

	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
