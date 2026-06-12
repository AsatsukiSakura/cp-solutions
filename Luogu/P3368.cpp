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
	Fenwick(vector<ll> &a){
		this->n=a.size()-1;
		tree.resize(n+1,0);
		for(int i=1;i<=n;i++){
			add(i,a[i]);
		}
	}
	void add(int x,int k){
		for(;x<=n;x+=(x&-x))
			tree[x]+=k;
	}
	ll getsum(int x){
		ll sum=0;
		for(;x;x-=(x&-x))
			sum+=tree[x];
		return sum;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=2;i--)
		a[i]=a[i]-a[i-1];
	Fenwick f(a);
	for(int i=1;i<=m;i++){
		int o,x,y,k;
		cin>>o;
		if(o==1){
			cin>>x>>y>>k;
			f.add(x,k);
			if(y<n)f.add(y+1,-k);
		}
		if(o==2){
			cin>>x;
			cout<<f.getsum(x)<<'\n';
		}
	}
	return 0;
}
