#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;cin>>n>>m;
	vector<vector<int>>a(n+2,vector<int>(n+2,0));
	int x1,y1,x2,y2;
	for(int i=1;i<=m;i++){
		cin>>x1>>y1>>x2>>y2;
		a[x1][y1]++;
		a[x2+1][y1]--;
		a[x1][y2+1]--;
		a[x2+1][y2+1]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]+=a[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]+=a[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<(a[i][j]&1);
		}
		cout<<endl;
	}
	return 0;
}
