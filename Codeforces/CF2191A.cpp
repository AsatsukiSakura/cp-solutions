#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
void solve(){
	int n;
	cin>>n;
	vector<pii>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		a[i].second=i&1;
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n-1;i++){
		if(a[i].second==a[i+1].second){
			cout<<"no\n";
			return ;
		}
	}
	cout<<"yes\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
