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
	vector<ll>a(n+1,0),pre(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<ll>ans(n+1,0);
	sort(a.begin(),a.end());
	partial_sum(a.begin(),a.end(),pre.begin());
	for(int i=2;i<=n;i++){
		for(int j=n-1;j-i>=0;j--){
			if(a[j+1]<pre[j]-pre[j-i]){
				ans[i+1]=pre[j+1]-pre[j-i];
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
