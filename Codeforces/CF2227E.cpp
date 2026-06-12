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
	/*维护每个高度最右边连续快数量和总数*/
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mn=a[n];
	vector<int>rt(n+2,0),cnt(n+2,0);
	for(int i=n;i>=1;i--){
		mn=min(mn,a[i]);
		rt[1]++,rt[mn+1]--;
		cnt[1]++,cnt[a[i]+1]--;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)rt[i]+=rt[i-1],cnt[i]+=cnt[i-1],ans+=(cnt[i]-rt[i]);
	ll mx=ans;
	for(int i=n;i>=1;i--){
		if(n+1-i<=rt[a[i]])mx=max(mx,ans+rt[a[i]]-n-1+i);
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
