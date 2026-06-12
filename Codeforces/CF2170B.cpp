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
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	ll sum=0;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=1ll*a[i];
		cnt+=(a[i]!=0);
	}
	cout<<min(1ll*n,min(1ll*cnt,sum-n+1))<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
