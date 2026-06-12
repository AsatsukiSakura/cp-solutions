#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
	ll k,num,tenpower[20],left[20],digitsum[20],ans=0;
	int i,dld,digit[20],addsum[20];
	tenpower[0]=1;
	addsum[0]=0;
	cin>>k;
	for(i=1;i<=16;i++){
		tenpower[i]=10*tenpower[i-1];
		addsum[i]=addsum[i-1]+i-1;
	}
	i=1;
	while(k>=9*i*tenpower[i-1]){
		k-=(9*i*tenpower[i-1]);
		i++;
	}
	dld=(i-k%i)%i;
	num=(k+dld)/i;
	num+=(tenpower[i-1]-1);
	digitsum[0]=0;
	left[0]=0;
	for(i=1;i<=16;i++){
		digitsum[i]=addsum[10]*tenpower[i-1]+10*digitsum[i-1];
		left[i]=num%tenpower[i];
		digit[i]=(left[i]-left[i-1])/tenpower[i-1];
	}
	for(i=1;i<=16;i++){
		ans+=(addsum[digit[i]]*tenpower[i-1]);
		ans+=digit[i]*(left[i-1]+1LL);
		ans+=digit[i]*digitsum[i-1];
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)	solve();
	return 0;
}
