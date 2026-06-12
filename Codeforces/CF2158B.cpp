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
	vector<int>a(2*n+1),cnt(2*n+1,0);
	int odd=0,even=0,quad=0;
	for(int i=1;i<=2*n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=2*n;i++){
		if(cnt[i]){
			if(cnt[i]%4==0)quad++;
			else if(cnt[i]%2==0) even++;
			else odd++;
		}
	}
	if(odd+even+quad==1){
		cout<<((n&1)?2:0)<<endl;
		return;
	}
	ll ans=2ll*even+odd+(quad-quad%2)*2ll;
	if((quad&1 )&& (odd))ans+=2;
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
