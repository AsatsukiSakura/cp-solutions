#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<double>a(8);
	double n=0,ans=5040;
	for(int i=1;i<=7;i++){
		cin>>a[i];
		n+=a[i];
		ans*=a[i];
	}
	for(int i=0;i<=5;i++){
		ans/=(n-i);
	}
	cout<<fixed<<setprecision(3)<<ans;
	return 0;
}
