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
struct Fenwick{
	int n;
	vector<ll>tree;
	Fenwick(int sz){
		n=sz;
		tree.assign(n+1,0);
	}
	void update(int x,ll k){
		for(;x<=n;x+=x&-x)
			tree[x]=max(k,tree[x]);
	}
	ll query(int x){
		ll r=0;
		for(;x>=1;x-=x&-x)
			r=max(r,tree[x]);
		return r;
	}
};
void solve(){
	int n;
	cin>>n;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<ll>dp=a;
	vector<vector<int>>p(n+1);
	Fenwick f(n);
	for(int i=1;i<=n;i++){
		for(int e:p[i])
			f.update(e,dp[e]);
		dp[i]+=f.query(i-a[i]-1);
		if(i+a[i]+1<=n)p[i+a[i]+1].push_back(i);
	}
	cout<<*max_element(dp.begin()+1,dp.end())<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
