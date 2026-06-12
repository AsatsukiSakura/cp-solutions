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
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int sa=accumulate(a.begin()+1,a.end(),0);
	int sb=accumulate(b.begin()+1,b.end(),0);
	if(sa%2==sb%2){cout<<"Tie"<<endl;return;}
	else{
		int m=-inf;
		for(int i=1;i<=n;i++){
			if(a[i]^b[i])m=i;
		}
		cout<<((m&1)?"Ajisai":"Mai")<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
