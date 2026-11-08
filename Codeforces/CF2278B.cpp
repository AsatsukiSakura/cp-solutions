#include<bits/stdc++.h>
using namespace std;
void solve(){
	int r,s,p;
	cin>>r>>s>>p;
	int m=max({r,s,p});
	char c;
	if(r==m)c='P';
	if(s==m)c='R';
	if(p==m)c='S';
	for(int i=1;i<=r+s+p;i++)cout<<c;
	cout<<'\n';
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
