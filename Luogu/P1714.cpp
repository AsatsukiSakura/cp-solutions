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
	int n,m;cin>>n>>m;
	deque<int>dq;
	int ans=INT_MIN;
	vector<int>a(n+1);a[0]=0;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		a[i]=a[i-1]+k;
	}
	dq.push_back(0);
	for(int i=1;i<=n;i++){
		while(!dq.empty()&&i-dq.front()>m){
			if(i==3)cout<<dq.front();
			dq.pop_front();
		}
		if(!dq.empty()){
			ans=max(ans,a[i]-a[dq.front()]);
		}
		while(!dq.empty() && a[dq.back()]>a[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout<<ans;
	return 0;
}
