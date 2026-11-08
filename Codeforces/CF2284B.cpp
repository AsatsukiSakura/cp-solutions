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
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.end());
	vector<int>b(n+1);
	for(int i=1,j=n-k+1;i<=k;i++,j++){
		b[i]=a[j];
	}
	for(int i=k+1,j=n-k;i<=n;i++,j--){
		b[i]=a[j];
	}
	if(k<n&&b[1]==b[k]&&b[k]==b[k+1]){cout<<"NO\n";return;}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
