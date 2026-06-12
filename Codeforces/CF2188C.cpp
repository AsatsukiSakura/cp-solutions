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
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	auto b=a;
	sort(b.begin()+1,b.end());
	if(b==a){cout<<"-1\n";return;}
	int mx=*max_element(a.begin()+1,a.end());
	int mn=*min_element(a.begin()+1,a.end());
	int ans=inf;
	for(int i=1;i<=n;i++){
		if(b[i]!=a[i])
			ans=min(ans,max(a[i]-mn,mx-a[i]));
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
