#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<int>	a(n+1),cnt(111,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=0;i<=100;i++){
		if(cnt[i]==0)
		{
			cout<<i<<endl;
			return;
		}
	}
	cout<<101;
	return;
}
int main(){
	int t;cin>>t;
	while(t--)	solve();
}
