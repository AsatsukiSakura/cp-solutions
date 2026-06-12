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
	int n;cin>>n;
	map<int,int>m;
	int s=0;m[s]=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		s+=pow(-1,a);
		if(m.count(s)){
			ans=max(ans,i-m[s]);
		}
		else m[s]=i;
	}
	cout<<ans;
	return 0;
}
