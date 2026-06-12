#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
#define int long long
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
bool check(int x,int n,int m,int k){
	if(x==0)return true;
	int dis=min(k-1,n-k);
	int a=min(x/2,dis);
	int b=x-a;
	int t=2*max(a,b)+min(a,b)-1;
	return t<=m;
}
void solve(){
	int n,m,k;
	
	cin>>n>>m>>k;
	int l=0,r=n-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,n,m,k))l=mid+1;
		else r=mid-1;
	}
	cout<<1+r<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
