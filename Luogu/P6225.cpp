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
	Fenwick(vector<int> &a){
		n=a.size()-1;
		tree=a;
		for(int i=1;i<=n;i++){
			if(i+(i&-i)<=n){
				tree[i+(i&-i)]^=tree[i];
			}
		}
	}
	void xr(int x,int k){
		for(;x<=n;x+=(x&-x))
			tree[x]^=k;
	}
	int getx(int x){
		int xs=0;
		for(;x>=1;x-=(x&-x))
			xs^=tree[x];
		return xs;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	vector<int>a1((n+1)/2+1),a2(n/2+1);
	for(int i=1;i<=n;i++){
		if(i&1)cin>>a1[(i+1)/2];
		else cin>>a2[i/2];
	}
	Fenwick odd(a1),even(a2);
	for(int i=1;i<=q;i++){
		int op,x,y;
		cin>>op>>x>>y;
		if(op&1){
			if(x&1){
				int z=odd.getx((x+1)/2)^odd.getx(x/2);
				odd.xr((x+1)/2,y^z);
			}
			else{
				int z=even.getx(x/2)^even.getx(x/2-1);
				even.xr(x/2,y^z);
			}
		}
		else{
			if((x&1)^(y&1)){
				cout<<0<<'\n';
			}
			else{
				if(x&1){
					cout<<(odd.getx((y+1)/2)^odd.getx(x/2))<<'\n';
				}
				else{
					cout<<(even.getx(y/2)^even.getx(x/2-1))<<'\n';
				}
			}
		}
	}
	return 0;
}
