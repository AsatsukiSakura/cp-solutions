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
void solve(){
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	vector<int>a(n,0),v(n,0);
	ll sum=0;
	for(int i=1;i<n;i++){
		a[i]=(s[i-1]!=s[i]);
		if(a[i])sum+=1ll*i*(n-i);
	}
	ll ev=1,od=0,p=0;
	for(int i=1;i<n;i++){
		v[i]=v[i-1]+a[i];v[i]&=1;
		if(v[i])od++;
		else ev++;
	}
	cout<<(sum+od*ev)/2<<' ';
	int f=0;
	for(int i=1;i<=q;i++){
		int x;
		cin>>x;
		if(x>1){
			sum-=(a[x-1]?1:-1)*1ll*(x-1)*(n-x+1);
			if((v[x-1]^f)){od--;ev++;}
			else{ev--;od++;}
			v[x-1]^=1;
			a[x-1]^=1;
		}
		if(x<n){
			sum-=(a[x]?1:-1)*1ll*x*(n-x);
			a[x]^=1;
		}
		if(x==1){
			f^=1;
			swap(ev,od);
			ev++;od--;
		}
		cout<<(sum+od*ev)/2<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
