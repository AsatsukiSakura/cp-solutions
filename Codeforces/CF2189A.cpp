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
	int n,h,l;
	cin>>n>>h>>l;
	int m1=0,m2=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x<=min(h,l)){
			m1++;
		}
		else if(x<=max(h,l)){
			m2++;
		}
	}
//	debug(m2);debug(m1);
	if(m2>=m1){
		cout<<m1<<'\n';
		return;
	}
	int cnt=0;
	m1-=m2;
	cnt+=m2;
	cnt+=m1/2;
	cout<<cnt<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
