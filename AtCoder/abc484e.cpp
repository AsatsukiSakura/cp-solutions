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
		tree.resize(n+1,0);
	}
	void update(int x,ll k){
		for(;x<=n;x+=x&-x)
			tree[x]+=k;
	}
	ll query(int x){
		ll r=0;
		for(;x>=1;x-=x&-x)
			r+=tree[x];
		return r;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<ll>a(n+1,0);
	ll l,r;
	cin>>l>>r;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<ll>sum=a;
	for(int i=1;i<=n;i++)
		sum[i]+=sum[i-1];
	auto tmp=sum;
	for(int i=1;i<=n;i++){
		tmp.push_back(sum[i]-l);
		tmp.push_back(sum[i]-r);
	}
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	Fenwick f(3*n+1);
	ll ans=0;
	for(int i=0;i<=n;i++){
		if(i!=0){
			int ridx=lower_bound(tmp.begin(),tmp.end(),sum[i]-r)-tmp.begin()+1;
			int lidx=lower_bound(tmp.begin(),tmp.end(),sum[i]-l)-tmp.begin()+1;
			ans+=f.query(lidx)-f.query(ridx-1);
		}
		int idx=lower_bound(tmp.begin(),tmp.end(),sum[i])-tmp.begin()+1;
		f.update(idx,1);
	}
	cout<<ans<<'\n';
	return 0;
}
