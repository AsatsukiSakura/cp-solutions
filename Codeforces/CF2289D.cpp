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
#define int long long
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
	int n;
	cin>>n;
	vector<int>a(n+1);
	vector<ll>s(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	if(*min_element(s.begin(),s.end())<0){
		cout<<"-1\n";
		return;
	}
	auto tmp=s;
	sort(tmp.begin()+1,tmp.end());
	tmp.erase(unique(tmp.begin()+1,tmp.end()),tmp.end());
	for(int i=1;i<=n;i++){
		s[i]=lower_bound(tmp.begin()+1,tmp.end(),s[i])-tmp.begin();
	}
	ll ans=0;
	Fenwick f(vector<ll>(n+1,0));
	for(int i=1;i<=n;i++){
		f.add(s[i],1);
		ans+=f.query(n)-f.query(s[i]);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}

