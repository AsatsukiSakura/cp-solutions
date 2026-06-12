#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
void solve(){
	int a,b;
	cin>>a>>b;
	if((int)log2(a)<(int)log2(b)){
		cout<<-1<<endl;return;
	}
	vector<int>ans;
	for(int i=1;i<=a;i<<=1){
		if((i&a)!=(i&b)){
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	for(int i:ans){
		cout<<i<<' ';
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
