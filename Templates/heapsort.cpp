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
void heapify(int *st,int *ed,int j){
	int n=ed-st;
	int *a=st-1;
	while(1){
		int lc=2*j;
		int rc=2*j+1;
		int large=j;
		if(lc<=n&&a[lc]>a[large])large=lc;
		if(rc<=n&&a[rc]>a[large])large=rc;
		if(large==j)break;
		swap(a[j],a[large]);
		j=large;
	}
}
void heapsort(int *st,int *ed){
	int n=ed-st;
	int *a=st-1;
	for(int i=n/2;i>=1;i--){
		int j=i;
		heapify(st,ed,j);
	}
	for(int i=n;i>1;i--){
		swap(a[1],a[i]);
		int j=1;
		heapify(st,a+i,j);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	heapsort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}
