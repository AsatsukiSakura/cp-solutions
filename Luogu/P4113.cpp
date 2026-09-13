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
struct pid{
	pii p;
	int id;
	int ans;
};
struct Fenwick{
	vector<ll>tree;
	int n;
	Fenwick(const vector<ll> &a){
		n=a.size()-1;
		tree=a;
		for(int i=1;i<=n;i++){
			if(i+(i&-i)<=n)
				tree[i+(i&-i)]+=tree[i];
		}
	}
	ll query(int x){
		ll r=0;
		for(;x>=1;x-=x&-x)r+=tree[x];
		return r;
	}
	void update(int x,ll k){
		for(;x<=n;x+=x&-x)tree[x]+=k;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,c,m;
	cin>>n>>c>>m;
	vector<int>a(n+1);
	vector<vector<int>>p(c+1);
	vector<pid>r(m+1);
	auto c1=[](const pid &a,const pid &b){
		return a.p.second<b.p.second;
	};
	auto c2=[](const pid &a,const pid &b){
		return a.id<b.id;
	};
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=m;i++){cin>>r[i].p.first>>r[i].p.second;
	r[i].id=i;}
	sort(r.begin()+1,r.end(),c1);
	Fenwick f(vector<ll>(n+1,0));
	for(int i=1,j=1;i<=n;i++){
		p[a[i]].push_back(i);
		int sz=p[a[i]].size();
		if(sz>=2){
			f.update(p[a[i]][sz-2],1);
			if(sz>=3)f.update(p[a[i]][sz-3],-1);
		}
		while(i==r[j].p.second){
			r[j].ans=f.query(r[j].p.second)-f.query(r[j].p.first-1);
			j++;
		}
	}
	sort(r.begin()+1,r.end(),c2);
	for(int i=1;i<=m;i++){cout<<r[i].ans<<'\n';}
	return 0;
}
