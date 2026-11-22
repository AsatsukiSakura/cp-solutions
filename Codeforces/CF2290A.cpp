#include<bits/stdc++.h>
using namespace std;
void solve(){
	vector<int>v(3);
	cin>>v[0]>>v[1]>>v[2];
	sort(v.begin(),v.end());
	if(v[1]==v[0]+1&&v[2]==v[0]+2){
		cout<<"YES\n";return;
	}
	cout<<"NO\n";
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
