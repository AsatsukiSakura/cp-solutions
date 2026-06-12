#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int ask(int l,int r){
	int psum,asum;
	cout<<1<<' '<<l<<' '<<r<<' '<<endl;
	cin>>psum;
	cout<<2<<' '<<l<<' '<<r<<' '<<endl;
	cin>>asum;
	return (asum-psum);
}
void solve(){
	int n; cin>>n;
	int l=1,r=n;
	int length=ask(l,r);
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		int ll=ask(l,mid);
		if(mid-l+1==length && ll==mid-l+1){
			cout<<'!'<<' '<<l<<' '<<mid<<endl;
			return;
		}
		if(r-mid==length && ll==0){
			cout<<'!'<<' '<<mid+1<<' '<<r<<endl;
			return;
		}
		if(ll!=length && ll!=0){
			cout<<'!'<<' '<<(mid+1-ll)<<' '<<(mid+(length-ll))<<endl;
			return;
		}
		if(ll==0){
			l=mid+1;
		}
		if(ll==length){
			r=mid;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
