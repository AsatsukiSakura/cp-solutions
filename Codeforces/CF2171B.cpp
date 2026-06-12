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
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]!=-1 && a[n]!=-1){
		cout<<abs(a[n]-a[1])<<endl;
		for(int i=1;i<=n;i++){
			cout<<(a[i]==-1?0:a[i])<<' ';
		}
	}
	else if(a[1]==-1&&a[n]==-1){
		cout<<0<<endl;
		for(int i=1;i<=n;i++){
			cout<<(a[i]==-1?0:a[i])<<' ';
		}
	}
	else{
		if(a[1]==-1)a[1]=a[n];
		if(a[n]==-1)a[n]=a[1];
		cout<<0<<endl;
		for(int i=1;i<=n;i++){
			cout<<(a[i]==-1?0:a[i])<<' ';
		}
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
