#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
int main(){
	int n,x;
	cin>>n>>x;
	vector<int>dp(n+1,1);
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			if((a[i]^a[j])>=x)dp[i]=max(dp[i],dp[j]+1);
		}
	}
	cout<<(*max_element(dp.begin()+1,dp.end()));
	return 0;
}
