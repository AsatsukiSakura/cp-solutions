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
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int>a(10,0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>=1;j--)
			cout<<i;
	}
	return 0;
}
