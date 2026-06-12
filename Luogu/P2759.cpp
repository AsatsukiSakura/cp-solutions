#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
ll n;
bool check(ll x){
	return((long double)log10(x)*x>=n);
}
ll b(ll l,ll h){
	if(l>h)return l;
	int mid=(l+h)/2;
	if(check(mid))	return b(l,mid-1);
	else	return b(mid+1,h);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;n--;
	ll x=b(1,3e8);
	cout<<x;
	return 0;
}
