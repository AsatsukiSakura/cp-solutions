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
	vector<int>p(n+1);
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int i;
	for(i=1;i<=n;i++){
		if(p[i]!=n+1-i)break;
	}
	if(i!=n+1){
		int j;
		for(j=i+1;j<=n;j++){
			if(p[j]==n+1-i){
				break;
			}
			//[i,j]
		}
		//cout<<i<<' '<<j<<'\n';
		reverse(p.begin()+i,p.begin()+j+1);
	}
	for(int i=1;i<=n;i++){
		cout<<p[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
