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
		tree=a;
		n=a.size()-1;
		for(int i=1;i<=n;i++){
			if(i+(i&-i)<=n)
				tree[i+(i&-i)]^=tree[i];
		}
	}
	void xr(int x,ll k){
		for(;x<=n;x+=(x&-x))
			tree[x]^=k;
	}
	ll query(int x){
		ll res=0;
		for(;x>=1;x-=(x&-x))
			res^=tree[x];
		return res;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	mt19937_64 rng(time(0));
	Fenwick f(vector<ll>(n+1,0));
	for(int i=1;i<=k;i++){
		int a,b;
		cin>>a>>b;
		if(f.query(b)^f.query(a-1))
			cout<<"No"<<endl;
		else{
			ll x=rng();
			f.xr(a,x);
			f.xr(b,x);
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
