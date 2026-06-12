#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int len=n;len>=1;len--){
		int diff=len;
		vector<int>cnt(n+1,0);
		for(int i=1;i<=len;i++){
			if(a[i]<=len){
				cnt[a[i]]++;
				if(cnt[a[i]]==1)diff--;
				if(cnt[a[i]]==2)diff++;
			}
		}
		int i=1,j=len;
		while(j<=n){
			if(diff==0){
				cout<<len;
				return 0;
			}
			if(j==n)break;
			if(a[++j]<=len){
				cnt[a[j]]++;
				if(cnt[a[j]]==2)diff++;
				if(cnt[a[j]]==1)diff--;
			}
			if(a[i]<=len){
				cnt[a[i]]--;
				if(cnt[a[i]]==0)diff++;
				if(cnt[a[i]]==1)diff--;
			}i++;
		}
	}
	cout<<0;
	return 0;
}

