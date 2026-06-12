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
	vector<ll>tree; Fenwick(const vector<ll> &a){
		tree=a;
		n=a.size()-1;
		for(int i=1;i<=n;i++){
			if(i+(i&-i)<=n)
				tree[i+(i&-i)]+=tree[i];
		}
	}
	void clear(){
		tree.assign(n+1,0);
	}
	void add(int x,int k){
		for(;x<=n;x+=(x&-x))
			tree[x]+=k;
	}
	ll query(int x){
		ll res=0;
		for(;x>=1;x-=(x&-x))
			res+=tree[x];
		return res;
	}
};
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	vector<ll>b(n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,c=-1;i<=n;i++){b[i]=b[i-1]+(c*=-1)*a[i];}
	auto v=b;
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<=n;i++)b[i]=lower_bound(v.begin(),v.end(),b[i])-v.begin()+1;
	Fenwick odd(vector<ll>(n+2,0));
	Fenwick even(vector<ll>(n+2,0));
	ll ans=0;
	for(int i=0;i<=n;i++){
		if(i&1){
			ans+=even.query(b[i]-1);
			odd.add(b[i],1);
		}
		else{
			ans+=(i>>1)-odd.query(b[i]);
			even.add(b[i],1);
		}
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
