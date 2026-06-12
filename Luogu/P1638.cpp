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
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1),c(m+1,0);
	int cnt=0;
	pii p={-inf,inf};
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,j=1;j<=n;){
		if(c[a[j]]==0)
			cnt++;
		c[a[j]]++;
		while(cnt==m){
			if(j-i<p.second-p.first)
				p={i,j};
			c[a[i]]--;
			if(c[a[i]]==0)
				cnt--;
			i++;
		}
		j++;
	}
	cout<<p.first<<' '<<p.second;
	return 0;
}
