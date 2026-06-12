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
struct DSU{
	vector<int>root;
	int n;
	DSU(int n){
		this->n=n;
		root.resize(n+1);
		iota(root.begin(),root.end(),0);
	}
	int find(int x){
		if(root[x]==x)return x;
		else return root[x]=find(root[x]);
	}
	void merge(int x,int y){
		root[find(y)]=find(x);
	}
};
struct ans{
	int l,r;
	string s;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int>v;v.push_back(-inf);
	vector<ans>a(m+1);
	for(int i=1;i<=m;i++){
		cin>>a[i].l>>a[i].r>>a[i].s;
		a[i].l--;
		v.push_back(a[i].l);
		v.push_back(a[i].r);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=m;i++){
		a[i].l=lower_bound(v.begin(),v.end(),a[i].l)-v.begin();
		a[i].r=lower_bound(v.begin(),v.end(),a[i].r)-v.begin();
	}
	DSU dsu(4*m);
	for(int i=1;i<=m;i++){
		if(a[i].s=="odd"){
			if(dsu.find(a[i].l)!=dsu.find(a[i].r)){
				dsu.merge(a[i].l+2*m,a[i].r);
				dsu.merge(a[i].l,a[i].r+2*m);
			}
			else{
				cout<<i-1;return 0;
			}
		}
		else{
			if(dsu.find(a[i].l+2*m)!=dsu.find(a[i].r)){
				dsu.merge(a[i].l,a[i].r);
				dsu.merge(a[i].l+2*m,a[i].r+2*m);
			}
			else{
				cout<<i-1;return 0;
			}
		}
	}
	cout<<m;
	return 0;
}
