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
	int n;
	cin>>n;
	int s=0;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		if(s>=a[i])s++;
		else s--;
	}
	cout<<s<<' ';s=0;
	for(int i=n;i>=1;i--){
		if(s>=a[i])s++;
		else s--;
	}
	cout<<s;
	return 0;
}
