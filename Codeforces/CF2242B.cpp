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
	cin>>n;
	vector<int>a(n+1,0),s1(n+1,0),s2(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){s1[i]=s1[i-1]+1,s2[i]=s2[i-1]+1;}
		if(a[i]==2){s1[i]=s1[i-1]-1,s2[i]=s2[i-1]+1;}
		if(a[i]==3){s1[i]=s1[i-1]-1,s2[i]=s2[i-1]-1;}
	}
	vector<int>r=s2;
	for(int i=n-2;i>=1;i--)
		r[i]=max(r[i+1],r[i]);
	for(int i=1;i<=n-2;i++){
		if(s1[i]>=0 && r[i+1]-s2[i]>=0){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
