#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mx=-1;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum+=a[j];
			mx=max(sum/(j-i+1),mx);
		}
	}
	cout<<mx<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
