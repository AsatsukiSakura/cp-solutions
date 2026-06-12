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
	Fenwick(const vector<ll>&a){
		n=a.size()-1;
		tree=a;
		for(int i=1;i<=n;i++){
			if(i+(i&-i)<=n)
				tree[i+(i&-i)]+=tree[i];
		}
	}
	void add(int x,int k){
		for(;x<=n;x+=(x&-x))
			tree[x]+=k;
	}
	int query(int x){
		ll res=0;
		for(;x>=1;x-=(x&-x))
			res+=tree[x];
		return res;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	vector<int>a(n+1),v(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	v=a;
	sort(v.begin()+1,v.end());
	auto it=unique(v.begin()+1,v.end());
	v.erase(it,v.end());
	for(int i=1;i<=n;i++){
		auto it=lower_bound(v.begin()+1,v.end(),a[i]);
		a[i]=it-v.begin();
	}
	Fenwick f(vector<ll>(n+1,0));
	ll ans=0;
	for(int i=n;i>=1;i--){
		ans+=1ll*f.query(a[i]-1);
		f.add(a[i],1);
	}
	cout<<ans;
	return 0;
}
