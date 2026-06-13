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
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]++;
	}
	vector<ll>sum(n+1,0);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+1ll*a[i];
	}
	//放l 到 r r-l+1 个 需要的位置数量：sum[r]-sum[l]+1
	int maxa=*max_element(a.begin(),a.end());
	int tot,ans=0;
	for(int i=1,j=1;j<=n;j++){
		tot=sum[j]-sum[i]+1;
		while(tot>maxa){
			i++;
			tot=sum[j]-sum[i]+1;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}