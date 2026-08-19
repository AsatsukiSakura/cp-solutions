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
void solve(){
	int n,k;
	set<int>s;
	cin>>n>>k;
	vector<int>p(n);
	int x=n^k;
	for(int i=1;i<=x;i<<=1)
		if(i&x)
			if(i>=n){cout<<"NO\n";return;}
			else s.insert(i);
	int j=0;
	for(int i=1;i<=n-1;i++)
		if(!s.count(i))
			p[j++]=i;
	p[j++]=0;
	for(auto it=s.begin();it!=s.end();it++)
		p[j++]=*it;
	cout<<"YES\n";
	for(int x:p)
		cout<<x<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
