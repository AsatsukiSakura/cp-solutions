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
	int ans=-1;
	vector<int>a(n+1);
	vector<int>pre(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int idx;
	for(int i=1;i<n;i++){
		int gap=abs(a[i+1]-a[i]);
		pre[i+1]=gap;
		if(gap>ans){
			ans=gap;
			idx=i;
		}
	}
	auto suf=pre;//suf[i]=(i-1)~n max gap
	//pre[i]=1~i max gap
	for(int i=2;i<=n;i++)pre[i]=max(pre[i-1],pre[i]);
	for(int i=n-1;i>=1;i--)suf[i]=max(suf[i+1],suf[i]);
	int mxgap=-1;
	for(int i=idx;i>=1;i--){
		int lgap=-1;
		int rgap=-1;
		if(i!=idx){mxgap=max(mxgap,abs(a[i]-a[i+1]));}
		if(i!=1)lgap=abs(2*a[idx]-a[i-1]);
		rgap=abs(2*a[i]-a[idx+1]);
		int cur=pre[i-1];
		if(idx+2<=n)cur=max(cur,suf[idx+2]);
		if(i!=1)cur=max(pre[i-1],cur);
		ans=min(ans,max({2*mxgap,lgap,rgap,cur}));
	}mxgap=-1;
	for(int i=idx+1;i<=n;i++){
		int lgap=-1;
		int rgap=-1;
		if(i!=idx+1){mxgap=max(mxgap,abs(a[i]-a[i-1]));}
		if(i!=n)rgap=abs(2*a[idx+1]-a[i+1]);
		lgap=abs(2*a[i]-a[idx]);
		int cur=pre[idx];
		if(i+2<=n)cur=max(cur,suf[i+2]);
		ans=min(ans,max({2*mxgap,lgap,rgap,cur}));
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
