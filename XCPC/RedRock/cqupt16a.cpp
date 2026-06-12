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
	/*
	A B C
	:
	A C B
	A C
	B A C
	*/
	cin>>n;
	string s;
	cin>>s;
	int _=0;
	for(char &c:s){
		_+=(c=='1');
	}
	if(s.size()<=n)
		s=string(n+1-s.size(),'0')+s;
	char a='A',b='B',c='C';
	for(int i=1;i<=n;i++){
		if(_==1&&s[i]=='1'){
			cout<<a<<' '<<c<<endl;
			return ;
		}
		if(s[i]=='1'){
			swap(a,b);
			_--;
		}
		else swap(b,c);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
