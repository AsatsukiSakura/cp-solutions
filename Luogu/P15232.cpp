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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;cin>>n>>m;
	vector<int>a(n+1,0);
	vector<int>b(m+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	sort(a.begin()+1,a.end());
	sort(b.begin()+1,b.end());
	ll ans=0;
	for(int i=1,j=m;;i++){
		if(i>=n+1){
			cout<<-1;
			return 0;
		}
		int cnt=1;
		while(b[--j]>=cnt+1){
			cnt++;
		}
		ans+=cnt*a[i];
		if(j==0)break;
	}
	cout<<ans;
	return 0;
}
