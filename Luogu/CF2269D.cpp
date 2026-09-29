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
	int n,q;
	cin>>n>>q;
	vector<int>a(n+1),st(n+1);
	set<int>s;
	s.insert(0),s.insert(3),s.insert(5),s.insert(6),s.insert(9),s.insert(10),s.insert(12),s.insert(15);
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		st[i]=s.count(a[i]);
		ans+=st[i];
	}
	cout<<ans<<' ';
	for(int i=1;i<=q;i++){
		int p,x;
		cin>>p>>x;
		int r=s.count(x);
		ans+=r-st[p];
		st[p]=r;
		cout<<ans<<' ';
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
