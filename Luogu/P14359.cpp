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
	int n,k;cin>>n>>k;
	vector<int>a(n+1),x(n+1,0);
	map<int,int>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	m[0]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(m.count(x[i]^k)){
			cnt++;
			m.clear();
		}
		m[x[i]]=i;
	}
	cout<<cnt;
	return 0;
}
