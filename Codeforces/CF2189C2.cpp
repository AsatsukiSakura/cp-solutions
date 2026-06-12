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
	vector<int>p(n+1);
	if((n&(n-1))==0){
		cout<<"-1\n";
		return;
	}
	if(n&1)p[n]=n;
	else{
		int tmp=1;
		while(2*tmp<n){
			tmp<<=1;
		}
		p[n]=tmp;
	}
	p[1]=p[n]^1;
	p[n-1]=n^(n-1);
	for(int i=2;i<=n-2;i++){
		p[i]=i^p[n-1];
	}
	for(int i=1;i<=n;i++){
		cout<<p[i]<<' ';
	}
	
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
