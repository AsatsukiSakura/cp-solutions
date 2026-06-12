#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,i,a[250005],q,pre[250005],l[250005],r[250005],pl[250005];
	pre[0]=0;cin>>n>>q;pl[0]=pl[1]=0; 
	for(i=1;i<=n;i++){
		cin>>a[i];pre[i]+=a[i];
		if(a[i]==a[i-1])	pl[i]++;
	}
	for(i=1;i<=q;i++){
		cin>>l[i]>>r[i]; 
	}
	for(i=1;i<=q;i++){
		if(pre[r[i]]-pre[l[i]]%3!=0 || (1+r[i]-l[i])%3!=0)
			{cout<<-1<<endl;	return;}
		if(pl[r[i]]-pl[l[i+1]]==0)	cout<<(4+r[i]-l[i])/3<<endl;
		else	cout<<(1+r[i]-l[i])/3<<endl;
	} 
}
int main(){
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}  

