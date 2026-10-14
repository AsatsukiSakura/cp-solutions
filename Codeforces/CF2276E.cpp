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
	int n;
	string s;
	cin>>n>>s;
	s=' '+s;
	vector<int>two,zero,five,six;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')zero.push_back(i);
		if(s[i]=='2')two.push_back(i);
		if(s[i]=='5')five.push_back(i);
		if(s[i]=='6')six.push_back(i);
	}
	two.push_back(n+1),five.push_back(n+2);
	zero.push_back(n+1),six.push_back(n+1);
	vector<ll>a(n+727,0);
	for(int i=1;i<=n;i++){
		int j=*lower_bound(two.begin(),two.end(),i);
		j=*lower_bound(zero.begin(),zero.end(),j);
		j=*lower_bound(two.begin(),two.end(),j);
		int k=*lower_bound(five.begin(),five.end(),j);
		j=*lower_bound(six.begin(),six.end(),j);
		if(k>j){
			a[i]+=n-i+1;
			a[i+1]-=n-i+1;
			a[i+1]-=1;
		}
		else{
			a[i]+=k-1-i+1+n-j+1;
			a[i+1]-=k-1-i+1+n-j+1;
			a[i+1]-=1;
			a[j+1]-=1;
			a[k+1]+=1;
		}
	}
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
