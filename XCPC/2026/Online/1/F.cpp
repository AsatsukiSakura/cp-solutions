#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	int n,m;
	cin>>n>>m;
	vector<ll>a(n+1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			a[i]+=x;	
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{ans+=(a[i]<a[i-1]);}
	cout<<ans;
	return 0;
}
