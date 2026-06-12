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
	int n,ans=0;cin>>n;
	vector<int>a(n+2),premax(n+1,-inf);
	a[0]=a[n+1]=inf;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		premax[i]=max(premax[i-1],a[i]);
		if(i%2==0)	a[i]=premax[i];
	}
	for(int i=1;i<=n;i+=2){
		if(a[i]-a[i-1]>=0 || a[i]-a[i+1]>=0){
			ans+=max(a[i]-a[i-1],a[i]-a[i+1])+1;
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
