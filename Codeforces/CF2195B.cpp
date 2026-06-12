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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i+=2){
		vector<int>b;
		for(int j=i;j<=n;j*=2){
			b.push_back(a[j]);
		}
		sort(b.begin(),b.end());
		for(int j=i,k=0;j<=n;j*=2,k++){
			a[j]=b[k];
		}
	}
	auto aa=a;
	sort(aa.begin()+1,aa.end());
	cout<<(aa==a?"YES":"NO")<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
