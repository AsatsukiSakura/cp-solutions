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
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int aa=0,bb=0,x=0,y=0;
	for(int i=1;i<=n;i++){
		if(a[i]>b[i])aa+=a[i];
		if(b[i]>a[i])bb+=b[i];
		if(a[i]==1 && b[i]==1)x++;
		if(a[i]==-1 && b[i]==-1)y++;
	}
	while(x--){
		if(aa<bb)aa++;
		else bb++;
	}
	while(y--){
		if(aa>bb)aa--;
		else bb--;
	}
	cout<<min(aa,bb)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
