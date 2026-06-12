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
	int n;cin>>n;
	vector<int>p(n+1);iota(p.begin()+1,p.end(),1);
	for(int i=n-2*(n/2)+1;i<=n-3;i+=2)swap(p[i],p[i+1]);
	for(int i=1;i<=n;i++)cout<<p[i]<<' ';cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
