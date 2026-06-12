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
struct person{
	int x,r;
	bool w=false;
};
void solve(){
	int n,m;
	ll k;
	cin>>n>>m>>k;
	multiset<int>box;
	for(int i=1;i<=m;i++){
		int tmp;
		cin>>tmp;
		box.insert(tmp);
	}
	vector<person>p(n+1);
	for(int i=1;i<=n;i++){
		int y,z;
		cin>>p[i].x>>y>>z;
		k-=y;
		p[i].r=max(0,z-y);
	}
	auto cmp=[](person a,person b){
		return a.r>b.r;
	};
	int cnt=0;
	sort(p.begin()+1,p.end(),cmp);
	for(int i=1;i<=n&&!box.empty();i++){
		auto it=box.lower_bound(p[i].x);
		if(it!=box.end()){
			p[i].w=true;
			box.erase(it);
			cnt++;
		}
	}
	for(int i=n;i>=1;i--){
		if(!p[i].w&&k-p[i].r>=0){
			k-=p[i].r;
			cnt++;
			p[i].w=true;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
