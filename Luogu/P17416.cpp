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
struct Node{
	int sz=0;
	int nxt[2]={};
	int cnt[30]={};
};
struct Trie{
	vector<Node>tree;
	Trie(){
		tree.emplace_back();
	}
	void insert(const int &x){
		int u=0;
		for(int i=29;i>=0;i--){
			int bit=(x>>i)&1;
			if(!tree[u].nxt[bit]){
				tree[u].nxt[bit]=tree.size();
				tree.emplace_back();
			}
			u=tree[u].nxt[bit];
			tree[u].sz++;
			for(int j=i;j>=0;j--){
				tree[u].cnt[j]+=((x>>j)&1);
			}
		}
	}
	ll query(const int &x,int k){
		ll r=0;
		int u=0;
		for(int i=29;i>=0;i--){
			int bit=(x>>i)&1;
			Node c;
			if(tree[u].nxt[1^bit])
				c=tree[tree[u].nxt[1^bit]];
			if(c.sz>k){
				r+=(1ll<<i)*k;
				u=tree[u].nxt[1^bit];
			}
			else{
				k-=c.sz;
				for(int j=i;j>=0;j--){
					r+=(1ll<<j)*(((x>>j)&1)?c.sz-c.cnt[j]:c.cnt[j]);
				}
				if(k==0)break;
				u=tree[u].nxt[bit];
			}
		}
		return r;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	Trie tr;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(i>=k){
			ans=max(ans,tr.query(a[i],k-1));
		}
		tr.insert(a[i]);
	}
	cout<<ans;
	return 0;
}
