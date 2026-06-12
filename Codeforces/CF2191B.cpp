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
	vector<int>a(n+1);
	int c0=0,c1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)c0++;
		if(a[i]==1)c1++;
	}
	if(c0==0){cout<<"no\n";return;}
	if(c0==1){cout<<"yes\n";return;}
	if(c0>=2&&c1==0){cout<<"no\n";return;}
	if(c0>=2&&c1>=1){cout<<"yes\n";return;}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
