#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	set<int>l;
	map<int,int,greater<int>>r;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(l.count(x))r[x]++;
		else l.insert(x);
	}
	cout<<l.size()+r.size()<<'\n';
	for(int x:l)cout<<x<<' ';
	for(auto&[x,c]:r)for(int i=1;i<=c;i++)cout<<x<<' ';
	
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
