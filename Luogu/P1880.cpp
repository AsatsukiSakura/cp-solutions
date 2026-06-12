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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>a(2*n+1),s(2*n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++){
		s[i]=s[i-1]+a[i];
	}
	vector<vector<int>>dpmin(2*n+1,vector<int>(2*n+1,inf));
	vector<vector<int>>dpmax(2*n+1,vector<int>(2*n+1,-inf));
	for(int i=1;i<=2*n;i++){
		dpmin[i][i]=0;
		dpmax[i][i]=0;
	}
	for(int l=1;l<=n-1;l++){
		for(int i=1;i<=2*n-l;i++){
			for(int j=0;j<=l-1;j++){
				dpmin[i][i+l]=min(dpmin[i][i+l],dpmin[i][i+j]+dpmin[i+j+1][i+l]+s[i+l]-s[i-1]);
				dpmax[i][i+l]=max(dpmax[i][i+l],dpmax[i][i+j]+dpmax[i+j+1][i+l]+s[i+l]-s[i-1]);
			}
		}
	}
	int mx=-inf,mn=inf;
	for(int i=1;i<=n;i++){
		mn=min(dpmin[i][i+n-1],mn);
		mx=max(dpmax[i][i+n-1],mx);
	}
	cout<<mn<<endl<<mx;
	return 0;
}
