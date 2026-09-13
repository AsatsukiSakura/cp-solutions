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
struct pt{
	int a,b,c,cnt,ans;
	bool operator !=(const pt& y){
		return (a!=y.a)||(b!=y.b)||(c!=y.c);
	}
};
struct Fenwick{
	vector<ll>tree;
	int n;
	Fenwick(const vector<ll> &a){
		n=a.size()-1;
		tree=a;
		for(int i=1;i<=n;i++){
			if(i+(i&-i)<=n)
				tree[i+(i&-i)]+=tree[i];
		}
	}
	ll query(int x){
		ll r=0;
		for(;x>=1;x-=x&-x)r+=tree[x];
		return r;
	}
	void update(int x,ll k){
		for(;x<=n;x+=x&-x)tree[x]+=k;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<pt>raw(n+1);
	for(int i=1;i<=n;i++){
		cin>>raw[i].a>>raw[i].b>>raw[i].c;
	}
	sort(raw.begin()+1,raw.end(),[](pt z,pt y){
		if(z.a!=y.a)return z.a<y.a;
		if(z.b!=y.b)return z.b<y.b;
		if(z.c!=y.c)return z.c<y.c;
		return false;
	});
	vector<pt>x(1);
	for(int i=1;i<=n;i++){
		if(i==1||raw[i]!=raw[i-1]){
			x.push_back(raw[i]);
			x.back().cnt=1;
			x.back().ans=0;
		}
		else x.back().cnt++;
	}
	Fenwick f(vector<ll>(k+1,0));
	auto cp=[](const pt &z,const pt &y){
		return z.b<y.b;
	};
	auto cdq=[&](auto &&self,int l,int r){
		if(l>=r)return;
		int mid=(l+r)>>1;
		self(self,l,mid);
		self(self,mid+1,r);
		int i=l;
		for(int j=mid+1;j<=r;j++){
			while(i<=mid&&x[i].b<=x[j].b){
				f.update(x[i].c,x[i].cnt);
				i++;
			}
			x[j].ans+=f.query(x[j].c);
		}
		for(int k=l;k<i;k++)f.update(x[k].c,-x[k].cnt);
		sort(x.begin()+l,x.begin()+r+1,cp);
	};
	cdq(cdq,1,x.size()-1);
	vector<int>res(n+1,0);
	for(int i=1;i<x.size();i++){x[i].ans+=x[i].cnt-1;
	res[x[i].ans]+=x[i].cnt;}
	for(int i=0;i<n;i++)cout<<res[i]<<'\n';
	return 0;
}
