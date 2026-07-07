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
	string s;
	cin>>s;
	int n=s.length();
	s=" "+s;
	string s1,s0;
	map<char,int>m0,m1;
	for(int i=1;i<=n;i++){
		if(i&1)s1.push_back(s[i]),m1[s[i]]++;
		else s0.push_back(s[i]),m0[s[i]]++;
		
	}
	sort(s1.begin(),s1.end()),sort(s0.begin(),s0.end());
	if(n&1){
		int x=0,y=0;
		for(char i='a';i<='z';i++){
			x+=(m1[i]&1);
			y+=(m0[i]&1);
		}
		if((x<=1&&y==0&&n%4==1)||(x==0&&y<=1&&n%4==3))cout<<"YES\n";
		else cout<<"NO\n";
	}
	else cout<<(s1==s0?"YES":"NO")<<'\n';
	return;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
