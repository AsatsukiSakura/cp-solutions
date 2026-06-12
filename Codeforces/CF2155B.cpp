#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k,i,j;
	cin>>n>>k;
	if(k==n*n-1){
		cout<<"NO"<<endl;return;
	}
	if(k>=n*(n-1)){
		cout<<"YES"<<endl;
		for(i=1;i<=n-1;i++){
			for(j=1;j<=n;j++){
				cout<<'U';
			}
			cout<<endl;
		}
		for(i=1;i<=k%n;i++){
			cout<<'U';
		}
		for(i=k%n+1;i<=n-1;i++){
			cout<<'R';
		}
		cout<<'L'<<endl;
		return;
	}
	else{
		cout<<"YES"<<endl;
		for(i=1;i<=(k-k%n)/n;i++){
			for(j=1;j<=n;j++){
				cout<<'U';
			}
			cout<<endl;
		}
		for(i=1;i<=k%n;i++)	cout<<'U';
		for(i=k%n+1;i<=n;i++)	cout<<'D';
		cout<<endl;
		for(i=(k-k%n)/n+2;i<=n;i++){
			for(j=1;j<=n-1;j++){
				cout<<'R';
			}
			cout<<'L'<<endl;
		}
		return;
	}
}
int main(){
	int t;cin>>t;
	while(t--)	solve();
	return 0;
} 
