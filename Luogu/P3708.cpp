#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;	cin>>n;
	vector<ll>ans(n+1),sigma(n+1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j*i<=n;j++){
			sigma[i*j]+=i;
		}
	}
	ans[0]=0;
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1]+n-sigma[i];
		cout<<ans[i]<<' ';
	}
	return 0;
}
