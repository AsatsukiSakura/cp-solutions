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
	string s;
	cin>>s;
	vector<int>a(s.size()+1);a[0]=0;
	for(int i=1;i<=s.size();i++){
		a[i]=a[i-1]+pow(-1,(s[i-1]=='G'));
	}
	map<int,int>m;
	int ans=0;
	for(int i=0;i<=s.size();i++){
		if(m.count(a[i])){
			ans=max(ans,i-m[a[i]]);
		}
		else	m[a[i]]=i;
	}
	cout<<ans;
	return 0;
}
