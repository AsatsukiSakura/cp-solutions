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
	int n;
	cin>>n;
	if(n==(n&-n)){cout<<"-1\n";return;}
	vector<int>p(n+1);
	p[n]=1;
	for(int i=2;i<=n-1;i++){
		p[i]=i^1;
	}
	p[1]=n&1?n-1:n;
	//C2
	if(n%2==0)swap(p[1],p[n&-n]);
	//C2
	for(int i=1;i<=n;i++){
		cout<<p[i]<<' ';
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
