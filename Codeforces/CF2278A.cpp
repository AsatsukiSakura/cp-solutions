#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x,y;
	cin>>x>>y;
	string a,b;
	cin>>a>>b;
	map<char,int>m[2];
	for(char c:a)m[0][c]++;
	for(char c:b)m[1][c]++;
	for(char c='a';c<='z';c++){
		if(c=='s'||c=='i'||c=='x'){if(m[1][c]!=m[0][c]-1){cout<<"NO\n";return;}}
		else{if(m[1][c]!=m[0][c]){cout<<"NO\n";return;}}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
