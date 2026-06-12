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
	int n,m;
	cin>>n>>m;
	vector<vector<int>>st(n+1,vector<int>(log2(n)+1));
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		st[i][0]=a[i];
	}
	for(int i=1;i<=log2(n);i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		int p=log2(r-l+1);
		cout<<max(st[l][p],st[r-(1<<p)+1][p])<<endl;
	}
	return 0;
}
