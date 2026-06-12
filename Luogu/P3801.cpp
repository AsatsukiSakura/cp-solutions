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
	vector<int>tree;
	Fenwick(const vector<int> &a){
		n=a.size()-1;
		tree=a;
		for(int i=1;i<=n;i++){
			if(i+(i&-i)<=n){
				tree[i+(i&-i)]+=tree[i];
			}
		}
	}
	void add(int x,int k){
		for(;x<=n;x+=(x&-x))
			tree[x]+=k;
	}
	int query(int x){
		int ans=0;
		for(;x>=1;x-=(x&-x))
			ans+=tree[x];
		return ans;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,q;
	cin>>n>>m>>q;
	Fenwick rs(vector<int>(n+1,0)),cs(vector<int>(m+1,0));
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op&1){
			int x,y;
			cin>>x>>y;
			rs.add(x,pow(-1,rs.query(x)-rs.query(x-1)));
			cs.add(y,pow(-1,cs.query(y)-cs.query(y-1)));
		}
		else{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			int r=rs.query(x2)-rs.query(x1-1);
			int c=cs.query(y2)-cs.query(y1-1);
			ll ans=1ll*r*(y2-y1+1)+1ll*c*(x2-x1+1)-2ll*r*c;
			cout<<ans<<'\n';
		}
	}
	return 0;
}
