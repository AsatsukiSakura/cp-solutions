#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
using pii=pair<int,int>;
const ll inf =1e16;
#define debug(x) cerr<<#x<<'='<<x<<' '
struct Fenwick{
	int n;
	vector<int>tree;
	Fenwick(int sz){
		n=sz;
		tree.resize(sz+1,0);
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
};
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q,m;
	cin>>n>>m>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	struct Query{
		int id;
		int l,r;
		int ans;
	};
	vector<Query>query(q+1,{0,0,0,0});
	for(int i=1;i<=q;i++){
		query[i].id=i;
		cin>>query[i].l>>query[i].r;
	}
	sort(query.begin()+1,query.end(),[&](const Query &a,const Query &b){
		return a.l<b.l;
	});
	struct Range{
		int idx,l,r;
	};
	vector<Range>range(n+1,{0,1,n});
	for(int i=1;i<=n;i++){
		range[i].idx=i;
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])!=a[i]&&(a[i]&a[j])!=a[j])
			{range[i].r=j-1;break;}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if((a[i]&a[j])!=a[i]&&(a[i]&a[j])!=a[j])
			{range[i].l=j+1;break;}
		}
	}
	vector<int>r(n+1,0);
	for(int i=1;i<=n;i++)
		r[i]=range[i].r;
	sort(range.begin()+1,range.end(),[](const Range &a,const Range &b){
		return a.l<b.l;
	});
	Fenwick f(n),fx(n);
	for(int i=1,j=1,k=1;i<=n;i++){
		if(i>1){
			f.update(r[i-1],-1);
			fx.update(i-1,-1);
		}
		while(j<=n&&range[j].l==i){
			f.update(range[j].r,1);
			fx.update(range[j].idx,1);
			j++;
		}
		while(k<=q&&query[k].l==i){
			query[k].ans=f.query(n)-f.query(query[k].r-1)-(fx.query(n)-fx.query(query[k].r));
			k++;
		}
	}
	sort(query.begin()+1,query.end(),[&](const Query &a,const Query &b){
		return a.id<b.id;
	});
	for(int i=1;i<=q;i++){
		cout<<query[i].ans<<'\n';
	}
}
