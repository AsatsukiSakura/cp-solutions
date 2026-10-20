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
	int k=1;
	while(k<=n)k<<=1;
	vector<int>a(2*(k-1)+1+1);
	int l=2*(k-1)+1;
	for(int i=1,j=l;i<=k-1;i++,j--){
		a[j]=a[i]=i&-i;
	}a[k]=0;
	cout<<l<<'\n';
	for(int i=1;i<=l;i++)cout<<a[i]<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
