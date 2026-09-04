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
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)continue;
		//debug(i);
		ans++;
		int j=i;
		while(j<=n&&(a[i]&a[j])==a[i])j++;--j;
		
		for(int k=j;k>=i;k--){a[k]-=a[i];}
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
