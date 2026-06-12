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
void merge2p(int *st1,int *ed1,int *st2,int *ed2,int *st){
	int n=ed1-st1+ed2-st2;
	int tmp[n+1];
	for(int i=1,*j=st1,*k=st2;i<=n;i++){
		if(k==ed2){
			tmp[i]=*j;
			j++;
		}
		else if(j==ed1){
			tmp[i]=*k;
			k++;
		}
		else if(*j<*k){
			tmp[i]=*j;
			j++;
		}
		else{
			tmp[i]=*k;
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		*st=tmp[i];
		st++;
	}
}
void mergesort(int *st,int *ed){
	int *a=st-1;
	int n=ed-st;
	if(n<=1)return;
	mergesort(a+1,a+n/2+1);
	mergesort(a+n/2+1,a+n+1);
	merge2p(a+1,a+n/2+1,a+n/2+1,a+n+1,a+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	mergesort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}
