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
	vector<int>tree;
	Fenwick(const vector<int> &a){
		tree=a;
		n=a.size()-1;
		for(int i=1;i<=n;i++)
			if(i+(i&-i)<=n)
				tree[i+(i&-i)]+=tree[i];
	}
	void update(int x,int k){
		for(;x<=n;x+=x&-x)
			tree[x]+=k;
	}
	int query(int x){
		int r=0;
		for(;x>=1;x-=x&-x)
			r+=tree[x];
		return r;
	}
	int find(int k){
		int p=1;
		while((p<<1)<=n)p<<=1;
		int r=0,x=0;
		for(int i=p;i>=1;i>>=1)
			if(x+i<=n&&r+tree[x+i]<k)
				x+=i,r+=tree[x];
		return x+1;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>p(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>p[i];
	Fenwick f(vector<int>(n+1,1));
	vector<int>a(n+1);
	for(int i=n;i>=1;i--){
		int idx=f.find(p[i]);
		a[idx]=i;
		f.update(idx,-1);
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
}
