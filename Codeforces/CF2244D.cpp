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
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1),b(m+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=m;j++)cin>>b[j];
	sort(b.begin()+1,b.end());
	ll mn=0,mx=0;
	for(int i=1,j=1;i<=n;i++){
		mx+=a[i];
		mn+=a[i];
		if(j<=m&&i==b[j]){
			ll tmp=max(-mn,mx);
			mn=min(mn,-mx);
			mx=tmp;
			j++;
		}
	}
	cout<<mx<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
