#include<bits/stdc++.h>
using namespace std;
void solve(){
	int i,j,l,a[111111],n,cnt[111111],ans=0,k,b,mx;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=500;i>=1;i--){
        memset(cnt,0,sizeof(cnt));
		int dif=i;
		int l=i*(i+1)/2;
		if(n<l)	continue;
		for(j=1;j<=l;j++){
			if(a[j]<=i){
				cnt[a[j]]++;
				if(cnt[a[j]]==a[j])dif--;
				if(cnt[a[j]]==a[j]+1)dif++;
			}
		}
        if(dif==0){
			cout<<i<<endl;return;}
		for(j=l+1;j<=n;j++){
			if(a[j-l]<=i){
				cnt[a[j-l]]--;
				if(cnt[a[j-l]]==a[j-l]-1)dif++;
				if(cnt[a[j-l]]==a[j-l])dif--;
			}
			if(a[j]<=i){
				cnt[a[j]]++;
				if(cnt[a[j]]==a[j]+1)dif++;
				if(cnt[a[j]]==a[j])dif--;
			}
			if(dif==0){
			cout<<i<<endl;return;}
		}
		
	}
	cout<<0<<endl;return;
}
int main(){
	int t;cin>>t;
	while(t--) solve();
	return 0;
}