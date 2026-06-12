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
	int n,k,r,c;
	cin>>n>>k>>r>>c;
	vector<vector<char>>a(n+1,vector<char>(n+1,'.'));
	for(int i=0;i<=n-1;i++){
		int x=(r+i>n?r+i-n:r+i);
		int y=(c+i>n?c+i-n:c+i);
		for(int j=0;j<=n-k;j+=k){
			a[x][y+j>n?y+j-n:y+j]='X';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<a[i][j];
		cout<<endl;
	}
}	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
