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
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	vector<bool>lv(n+1,1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int d=29;d>=0;d--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((lv[i])&&((a[i]>>d)&1))cnt++;
		}
		if(cnt>=m){
			ans+=(1<<d);
			for(int i=1;i<=n;i++){
				if(lv[i]){
					if((a[i]>>d)&1) {}
					else lv[i]=0;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
