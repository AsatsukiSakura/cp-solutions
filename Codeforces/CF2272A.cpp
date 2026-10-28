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
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1),pos(n),c(n,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
	}
	for(int i=1;i<=n-k+1;i++){
		c[a[i]]++;
	}
	int mex=0;
	for(;mex<n;mex++){
		if(c[mex]==0)break;
	}
	if(mex==n-k+1){
		cout<<"-1\n";
		return;
	}
	int cnt=0;
	for(int i=0;i<=n-k;i++){
		if(pos[i]>n-k+1)cnt++;
	}
	for(int v=n-k+1;v>mex;v--){
		if(cnt==1){
			int p1=-1,p2=-1;
			for(int i=0;i<v;i++){
				if(pos[i]>n-k+1){
					p1=pos[i];
					break;
				}
			}
			for(int i=1;i<=n-k+1;i++){
				if(a[i]>=v){
					p2=i;break;
				}
			}
			cout<<p2<<" "<<p1<<"\n";
			return;
		}
		if(pos[v-1]>n-k+1)cnt--;
	}
	cout<<"-1\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
