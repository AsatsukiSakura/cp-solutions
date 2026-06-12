#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	vector<int>a(n+1),c(n+1);
	ll sum=0;
	for(int i=1;i<=n;i++)
		cin>>a[n];
	for(int i=1;i<=n-1;i++)
		sum+=max(a[i],a[i+1]);
	cout<<sum;
	return 0;
}
