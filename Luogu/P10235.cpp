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
	vector<int>tree; Fenwick(const vector<int> &a){
		tree=a;
		n=a.size()-1;
		for(int i=1;i<=n;i++){
			if(i+(i&-i)<=n)
				tree[i+(i&-i)]+=tree[i];
		}
	}
	void clear(){
		tree.assign(n+1,0);
	}
	void add(int x,int k){
		for(;x<=n;x+=(x&-x))
			tree[x]+=k;
	}
	int query(int x){
		int res=0;
		for(;x>=1;x-=(x&-x))
			res+=tree[x];
		return res;
	}
};
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	auto va=a;
	sort(va.begin()+1,va.end());
	va.erase(unique(va.begin()+1,va.end()),va.end());
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(va.begin()+1,va.end(),a[i])-va.begin();
	}
	ll l=0,h=1e10;
	Fenwick f(vector<int>(n+1,0));
	vector<int>history;
	while(l<=h){
		ll ip=0;
		ll mid=(l+h)/2;
		ll invp=0;
		ll seg=1;
		f.clear();
		history.clear();
		for(int i=n;i>=1;i--){
			if(invp+f.query(a[i]-1)>mid){
				seg++;
				invp=0;
				for(int p:history){
					f.add(p,-1);
				}
				history.clear();
			}
			f.add(a[i],1);
			history.push_back(a[i]);
			invp+=f.query(a[i]-1);
		}
		if(seg>k){l=mid+1;}
		else h=mid-1;
	}
	cout<<l<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
