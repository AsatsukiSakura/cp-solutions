#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=99999997;
const ll inf=0x3f3f3f3f;
struct Fenwick{
	int n;
	vector<int>tree;
	Fenwick(const vector<int> &a){
		tree=a;
		n=a.size()-1;
		for(int i=1;i<=n;i++){
			if(i+(i&-i)<=n)
				tree[i+(i&-i)]+=tree[i];
		}
	}
	void add(int x,int k){
		for(;x<=n;x+=(x&-x)){
			tree[x]+=k;
			tree[x]%=mod;
		}
	}
	int query(int x){
		int res=0;
		for(;x>=1;x-=(x&-x)){
			res+=tree[x];
			res%=mod;
		}
		return res;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	vector<int>a(n+1),b(n+1),va(n+1),vb(n+1),p(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	va=a;vb=b;
	sort(va.begin()+1,va.end());
	sort(vb.begin()+1,vb.end());
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(va.begin(),va.end(),a[i])-va.begin();
		b[i]=lower_bound(vb.begin(),vb.end(),b[i])-vb.begin();
	}
	for(int i=1;i<=n;i++){
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		b[i]=p[b[i]];
	}
	ll ans=0;
	Fenwick f(vector<int>(n+1,0));
	for(int i=n;i>=1;i--){
		f.add(b[i],1);
		ans+=f.query(b[i]-1);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
