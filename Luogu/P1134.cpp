#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,n2=0,n5=0;
	ll ans=1;
	cin>>n;
	for(int i=2;i<=n;i++){
		int ii=i;
		while(ii%2==0){
			ii/=2;
			n2++;
		}
		while(ii%5==0){
			ii/=5;
			n5++;
		}
		ii%=10;
		ans*=ii;
		ans%=10;
	}
	if(n2>=n5){
		if(n2==n5);
		else{
			ans*=pow(2,((n2-n5)-1)%4+1);
			ans%=10;
		}
	}
	else{
		ans*=5;
		ans%=10;
	}
	ans%=10;
	cout<<ans;
	return 0;
}
