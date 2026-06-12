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
	int n;cin>>n;
	vector<int>a(n+1);
	vector<vector<int>>pos(n+1);
	vector<vector<int>>facs(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=n)		
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n-1;j+=i){
			facs[j].push_back(i);
		}
	}
	int ans=0;
	for(int len=1;len<=n-1;len++){
		int c1=0;
		for(int d:facs[len]){
			if(1ll*d*d<len)continue;
			
			int cnt=0;
			for(int p:pos[d]){
				if(p+len<=n&&1ll*a[p]*a[p+len]==len){
					cnt++;
				}
				if(p-len>=1&&1ll*a[p]*a[p-len]==len){
					cnt++;
				}
			}
			if(1ll*d*d==len)cnt/=2;
			c1+=cnt;
		}
		ans+=c1;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("test.in","r",stdin);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
