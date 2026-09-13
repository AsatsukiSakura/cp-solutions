#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005];
void solve(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int sum=0,ans=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		ans=min(ans,sum*2-a[i]+(a[i]+a[i+1])*(n-i));
	}
	reverse(a+2,a+n+1);
	sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		ans=min(ans,sum*2-a[i]+(a[i]+a[i+1])*(n-i));
	}
	printf("%lld\n",ans);
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
