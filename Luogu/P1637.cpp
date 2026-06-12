#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
struct Fenwick{
	int n;
	vector<ll>tree;
	Fenwick(const vector<ll> &a){
		tree=a;
		n=a.size()-1;
		for(int i=1;i<=n;i++)
			if(i+(i&-i)<=n)
				tree[i+(i&-i)]+=tree[i];
	}
	void clear(){
		tree.assign(n+1,0);
	}
	void add(int x,ll k){
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	auto va=a;
	sort(va.begin()+1,va.end());
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(va.begin()+1,va.end(),a[i])-va.begin();
	}
	vector<ll>bi(n+1);
	Fenwick f(vector<ll>(n+1,0));
	for(int i=1;i<=n;i++){
		bi[i]=f.query(a[i]-1);
		f.add(a[i],1);
	}
	f.clear();
	vector<ll>tri(n+1);
	for(int i=1;i<=n;i++){
		tri[i]=f.query(a[i]-1);
		f.add(a[i],bi[i]);
	}
	cout<<accumulate(tri.begin()+1,tri.end(),0ll);
	return 0;
}
