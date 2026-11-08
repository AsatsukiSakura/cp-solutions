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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=' '+s;
	vector<int>pos(26,-inf);
	int ans=inf;
	for(int i=1;i<=n;i++){
		ans=min(ans,i-pos[s[i]-'a']);
		pos[s[i]-'a']=i;
	}
	cout<<(n-ans>0?n-ans:-1);
	return 0;
}
