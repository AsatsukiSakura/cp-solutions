#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,h,a[111111];
bool check(ll target,ll p,ll b){
	int i=1;
	for(i=1;i<=n;i++){
		if(target>a[i])	b-=(target-a[i]+p-1)/p;
		if(b<0)	return false;
	}
	return true;
}
ll binaryanswer(ll low,ll high,ll f,ll g){
	ll mid=(low+high)/2;
	if(low>high)	return high;
	if(check(mid,f,g)){
		low=mid+1;
		return binaryanswer(low,high,f,g);
	}
	else{
		high=mid-1;
		return binaryanswer(low,high,f,g);
	}
}
int main(){
	int i;
	cin>>n>>m>>k>>h; 
	for(i=1;i<=n;i++)	cin>>a[i]; 
	sort(a+1,a+n+1); 
	ll firstbestsol=binaryanswer(0,LLONG_MAX,h,k);
	for(i=1;i<=n;i++){
		if(firstbestsol>=a[i] && k>0){
			k-=max(((firstbestsol-a[i]+h-1)/h),1LL);
			a[i]+=h*max(((firstbestsol-a[i]+h-1)/h),1LL);
		}	
	}
	sort(a+1,a+n+1);
	
	for(i=1;i<=k;i++)
		a[i]+=h;
	sort(a+1,a+n+1);
	cout<<binaryanswer(0,LLONG_MAX,1,m);
	return 0;
} 
