#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
void solve(){
	int n;
	cin>>n;
	string s,t;
	map<char,int>ms,mt;
	cin>>s>>t;
	for(int i=1;i<=n;i++){
		ms[s[i-1]]++;
		mt[t[i-1]]++;
	}
	for(auto [c,cnt] : ms){
		if(mt[c]!=cnt){
			cout<<"no"<<endl;
			return;
		}
	}
	cout<<"yes"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
