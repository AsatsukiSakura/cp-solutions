#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	string s;
	cin>>n>>s;
	s='B'+s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=(s[i]==s[i-1]);
	}cout<<cnt<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
