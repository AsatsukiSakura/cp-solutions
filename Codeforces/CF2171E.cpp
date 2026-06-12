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
	for(int i=0;i<=n/6;i++){
		if(6*i+4<=n)cout<<6*i+4<<' ';
		if(6*i+1<=n)cout<<6*i+1<<' ';
		if(6*i+2<=n)cout<<6*i+2<<' ';
	}
	for(int i=0;i<=n/6;i++){
		if(6*i+3<=n)cout<<6*i+3<<' ';
		if(6*i+5<=n)cout<<6*i+5<<' ';
		if(6*i+6<=n)cout<<6*i+6<<' ';
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
