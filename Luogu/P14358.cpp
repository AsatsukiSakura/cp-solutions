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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,a;
	cin>>n>>m;
	set<int>s;
	cin>>a;
	for(int i=2;i<=m*n;i++){
		int b;
		cin>>b;
		s.insert(b);
	}
	s.insert(a);
	auto it=s.find(a);
	int pos=distance(it,s.end());
	cout<<pos;
	int c=(pos+n-1)/n;
	int r=(c&1?(pos-1)%n+1:n-(pos-1)%n);
	cout<<c<<' '<<r;
	return 0;
}
