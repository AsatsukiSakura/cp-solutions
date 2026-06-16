#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
void solve(){
	int n;
	cin>>n;
		cout<<"Yes\n";
	vector<vector<int>>a(n+1);
	vector<int>mid(n+1),ub(n+1);
	for(int i=1;i<=n;i++)mid[i]=n;
	for(int i=1;i<=n;i++)ub[i]=n-2+i;
	swap(ub[1],ub[2]);
	for(int i=2;i<=n-1;i++)a[i]=mid;
	a[1]=a[n]=ub;
	for(int i=2;i<=n-1;i++){
		a[i][1]=i-1;
	}
	a[1][n-1]=2*n-1;
	a[n][n]=2*n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;t=1;
	while(t--)solve();
}
