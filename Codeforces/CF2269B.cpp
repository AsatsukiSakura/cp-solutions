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
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=1000;j++){
			int tmp=0;
			while(a[i]){
				tmp+=(a[i]%10)*(a[i]%10);
				a[i]/=10;
			}
			a[i]=tmp;
		}
	}
	map<int,int>mp;
	int ans=0;
	for(int i=1;i<=n;i++)mp[a[i]]++;
	for(auto &[val,cnt]:mp){
		ans+=(cnt)*(cnt-1)/2;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
