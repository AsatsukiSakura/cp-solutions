#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,i,a[250005],q,pre[250005],l[250005],r[250005],precnt[250005];
	pre[0]=0;cin>>n>>q;precnt[0]=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=3) pre[i]=pre[i-1]+1;
		else pre[i]=pre[i-1]+log2(a[i]-2)+1;
		if(a[i]>=3 && ((a[i]-1)&(a[i]-2))==0) precnt[i]=precnt[i-1]+1;
		else precnt[i]=precnt[i-1];
	}
	for(i=1;i<=q;i++){
		cin>>l[i]>>r[i]; 
	}
	for(i=1;i<=q;i++){
		cout<<pre[r[i]]-pre[l[i]-1]+(precnt[r[i]]-precnt[l[i]-1])/2<<endl; 
	} 
}
int main(){
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
