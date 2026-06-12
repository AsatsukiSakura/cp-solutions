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
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=20;i>=0;i--){
		int sa=0,sb=0;
		for(int j=1;j<=n;j++){
			sa+=((a[j]>>i)&1);
			sb+=((b[j]>>i)&1);
		}
		if(sa%2==sb%2){continue;}
		else{
			int m=-inf;
			for(int j=1;j<=n;j++){
				if(((a[j]>>i)&1)^((b[j]>>i)&1))m=j;
			}
			cout<<((m&1)?"Ajisai":"Mai")<<endl;
			return;
		}
	}
	cout<<"Tie"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
