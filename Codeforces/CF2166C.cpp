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
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1),c(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		c[i]=max(a[i],a[i%n+1]);
		sum+=c[i];
	}
	cout<<sum-*max_element(c.begin()+1,c.end())<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
