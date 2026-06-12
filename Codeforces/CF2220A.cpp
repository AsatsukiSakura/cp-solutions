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
	vector<int>a(n+1),c(101,0);
	bool b=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
		if(c[a[i]]>1)b=false;
	}
	if(b){
		sort(a.begin()+1,a.end(),greater<int>());
		for(int i=1;i<=n;i++)cout<<a[i]<<' ';
		cout<<'\n';
	}
	else cout<<"-1\n";
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
