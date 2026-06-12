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
	int n;cin>>n;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	stack<int>st;
	ll ans=0;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]<a[i]){
			int b=st.top();
			st.pop();
			if(st.empty())break;
			int l=st.top();
			int h=min(a[l],a[i])-a[b];
			int w=i-l-1;
			ans+=1ll*w*h;
		}
		st.push(i);
	}
	cout<<ans;
	return 0;
}
