#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
using pii=pair<int,int>;
struct Node{
	int l,r;
	int mn,mx;
	int lazymn,lazymx;
};
struct Segtree{
	vector<Node>tree;
	int ls(int x){return x<<1;}
	int rs(int x){return x<<1|1;}
	void build(int x,int l,int r,const vector<int> &a){
		tree[x].l=l;
		tree[x].r=r;
		tree[x].lazymn=0;
		tree[x].lazymx=0;
		if(l==r){
			tree[x].mn=a.empty()?0:a[l]==-1?inf:a[l];
			tree[x].mx=a.empty()?0:a[l]==-1?-inf:a[l];
			return;
		}
		int mid=(l+r)/2;
		build(ls(x),l,mid,a);
		build(rs(x),mid+1,r,a);
		pushup(x);
	}
	Segtree(int n,const vector<int> &a={}){
		tree.resize(4*n+1);
		build(1,1,n,a);
	}
	void pushup(int x){
		tree[x].mn=min(tree[ls(x)].mn,tree[rs(x)].mn);
		tree[x].mx=max(tree[ls(x)].mx,tree[rs(x)].mx);
	}
	void apply(int x,int k1,int k2){
		tree[x].lazymn=k1;
		tree[x].lazymx=k2;
		tree[x].mn=k1;
		tree[x].mx=k2;
	}
	void pushdown(int x){
		if(tree[x].lazymn||tree[x].lazymx){
			apply(ls(x),tree[x].lazymn,tree[x].lazymx);
			apply(rs(x),tree[x].lazymn,tree[x].lazymx);
		}
		tree[x].lazymn=0;
		tree[x].lazymx=0;
	}
	void update(int l,int r,int k1,int k2,int x=1){
		if(l<=tree[x].l&&tree[x].r<=r) 
			return apply(x,k1,k2);
		pushdown(x);
		int mid=(tree[x].l+tree[x].r)/2;
		if(l<=mid) 	
			update(l,r,k1,k2,ls(x));
		if(r>mid)  
			update(l,r,k1,k2,rs(x));
		pushup(x);
	}
	pii query(int l,int r,int x=1){
		pii ans={inf,-inf};
		if(l<=tree[x].l&&tree[x].r<=r) 
			return {tree[x].mn,tree[x].mx};
		pushdown(x);
		int mid=(tree[x].l+tree[x].r)/2;
		if(l<=mid){
			pii res=query(l,r,ls(x));
			ans.first=min(ans.first,res.first);
			ans.second=max(ans.second,res.second);
		}
		if(r>mid){
			pii res=query(l,r,rs(x));
			ans.first=min(ans.first,res.first);
			ans.second=max(ans.second,res.second);
		}
		return ans;
	}
};
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	Segtree sg(n,a);
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op==1){
			int j,x;
			cin>>j>>x;
			if(x!=-1)	sg.update(j,j,x,x);
			else sg.update(j,j,inf,-inf);
		}
		if(op==2){
			int l,r;
			cin>>l>>r;
			auto [x,y]=sg.query(l,r);
			if(x!=y&&x!=inf&&y!=-inf)
				cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
}
