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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<ll>a(n+1),sum(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int k=3;k<=n;k++){
		for(int i=n;i>=k;i--){
			if(a[i]<sum[i-1]-sum[i-k]){
				cout<<k<<' ';
				break;
			}
		}
	}
}