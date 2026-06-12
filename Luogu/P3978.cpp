#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	vector<double>e(n+1,0);
	vector<__int128>catalan(n+1,0);catalan[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i-1;j++){
			catalan[i]+=catalan[j]*catalan[i-j-1];
		}
	}
	e[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i-1;j++){
			double prob=(double)(catalan[j]*catalan[i-j-1])/catalan[i];
			e[i]+=prob*(e[j]+e[i-j-1]);
		}
	}
	cout<<fixed<<setprecision(9)<<e[n];
	return 0;
}
