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
	string s;
	cin>>s;
	s=' '+s;
	int cnt=0;
	vector<int>a,b;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			cnt++;
			a.push_back(i);
		}
		else b.push_back(i);
	}
	if(cnt==0){cout<<"0\n";return;}
	if((cnt&1)&&(n&1))cout<<"-1\n";
	else{
		if(cnt&1){
			cout<<n-cnt<<'\n';
			for(int i:b)cout<<i<<' ';
			cout<<'\n';
		}
		else if(cnt!=0){
			cout<<cnt<<'\n';
			for(int i:a)cout<<i<<' ';
			cout<<'\n';
		}
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
/*
3
6
000000
6
110011
6
110001
*/
