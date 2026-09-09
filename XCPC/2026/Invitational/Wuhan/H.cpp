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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,q;
	cin>>n>>m>>q;
	multiset<int>x,y,dx,dy;
	x.insert(0),x.insert(n);
	y.insert(0),y.insert(m);
	dx.insert(n),dy.insert(m);
	for(int i=1;i<=q;i++){
		int op,k;
		cin>>op>>k;
		if(op&1){
			auto it=x.lower_bound(k);
			int len=*it-*prev(it);
			dx.erase(dx.find(len));
			dx.insert(*it-k),dx.insert(k-*prev(it));
			x.insert(k);
			cout<<1ll**dx.rbegin()**dy.rbegin()<<'\n';
		}
		else{
			auto it=y.lower_bound(k);
			int len=*it-*prev(it);
			dy.erase(dy.find(len));
			dy.insert(*it-k),dy.insert(k-*prev(it));
			y.insert(k);
			cout<<1ll**dx.rbegin()**dy.rbegin()<<'\n';
		}
	}
	return 0;
}
