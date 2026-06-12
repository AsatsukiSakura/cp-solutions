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
	int n,a;
	cin>>n>>a;
	int ls=0,m=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x>a)m++;
		if(x<a)ls++;
	}
	if(m>=ls)cout<<a+1;
	else cout<<a-1;
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
