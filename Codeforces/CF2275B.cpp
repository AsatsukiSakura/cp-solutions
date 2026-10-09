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
	stack<int>st;
	string s;
	cin>>n>>s;
	s=' '+s;
	vector<bool>p(n+1,1);
	for(int i=1;i<=n;i++){
		if(s[i]=='1')st.push(i);
		if(s[i]=='2'){
			if(!st.empty()){
				p[st.top()]=0;
				st.pop();
			}
			else p[i]=0;
		}
		if(s[i]=='3'){
			p[i]=0;
		}
	}
	int o=0;
	for(int i=1;i<=n;i++){
		o+=p[i];
	}
	cout<<o<<'\n';
	for(int i=1;i<=n;i++)
		if(p[i])cout<<i<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
