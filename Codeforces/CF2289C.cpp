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
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	stack<int>st;
	vector<int>l(n+1,0),r(n+1,n+1);
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]>a[i]){
			r[st.top()]=i;
			st.pop();
		}
		if(!st.empty())l[i]=st.top();
		st.push(i);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(l[i]==i-1||r[i]==i+1)ans+=r[i]-l[i]-1;
		else ans++,++ans;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
