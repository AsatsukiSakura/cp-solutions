#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int l,r;
	int sum;
	int lazy;
};
struct Segtree{
	vector<Node>tree;
	int ls(int x){return x<<1;}
	int rs(int x){return x<<1|1;}
	void build(int x,int l,int r,const vector<int> &a){
		tree[x].l=l;
		tree[x].r=r;
		tree[x].lazy=0;
		if(l==r){
			tree[x].sum=a.empty()?0:a[l];
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
		tree[x].sum=tree[ls(x)].sum+tree[rs(x)].sum;
	}
	void apply(int x,int k){
		tree[x].sum+=(tree[x].r-tree[x].l+1)*k;
		tree[x].lazy+=k;
	}
	void pushdown(int x){
		if(!tree[x].lazy)return;
		apply(ls(x),tree[x].lazy);
		apply(rs(x),tree[x].lazy);
		tree[x].lazy=0;
	}
	void update(int l,int r,int k,int x=1){
		if(l<=tree[x].l&&tree[x].r<=r) 
			return apply(x,k);
		pushdown(x);
		int mid=(tree[x].l+tree[x].r)/2;
		if(l<=mid) 	
			update(l,r,k,ls(x));
		if(r>mid)  
			update(l,r,k,rs(x));
		pushup(x);
	}
	int query(int l,int r,int x=1){
		int ans=0;
		if(l<=tree[x].l&&tree[x].r<=r) 
			return tree[x].sum;
		pushdown(x);
		int mid=(tree[x].l+tree[x].r)/2;
		if(l<=mid) 
			ans+=query(l,r,ls(x));
		if(r>mid)  
			ans+=query(l,r,rs(x));
		return ans;
	}
};
signed main(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	Segtree sg(n,a);
	for(int i=1;i<=m;i++){
		int op;
		cin>>op;
		if(op==1){
			int x,y,k;
			cin>>x>>y>>k;
			sg.update(x,y,k);
		}
		else{
			int x,y;
			cin>>x>>y;
			cout<<sg.query(x,y)<<'\n';
		}
	}
}
