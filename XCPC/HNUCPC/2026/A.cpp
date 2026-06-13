#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>a(n+1,0),b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	bool f=false;
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]<b[i])f=true;
	}
	cout<<(f?"YES\n":"NO\n");
	return 0;
}
