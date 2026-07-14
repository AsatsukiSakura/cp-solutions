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
	if(n==1){cout<<1<<'\n';return;}
	if(n==2){cout<<-1<<'\n';return;}
	vector<ll>a(n+1);
	a[1]=1,a[2]=2,a[3]=3;
	for(int i=4;i<=n;i++){
		a[i]=a[i-1]*2ll;
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
