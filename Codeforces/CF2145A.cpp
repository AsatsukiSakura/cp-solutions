#include<bits/stdc++.h>
#define ll long long
const ll mod=998244353;
using namespace std;
void solve(){
	int n;
	cin>>n;
	cout<<(3-n%3)%3<<endl;
}
int main(){
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
