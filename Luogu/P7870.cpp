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
	int n;
	cin>>n;
	stack<pii>st;
	for(int i=1;i<=n;i++){
		int op;
		cin>>op;
		if(op==1){
			int l,r;
			cin>>l>>r;
			st.push({l,r});
		}
		if(op==2){
			ll k,ans=0;
			cin>>k;
			while(!st.empty()&&k>=st.top().second-st.top().first+1){	
				pii p=st.top();
				st.pop();
				k-=(p.second-p.first+1);
				ans+=(p.second-p.first+1)*(1ll*p.second+p.first)/2;	
			}
			if(!st.empty()){
				pii p=st.top();
				ans+=k*(2ll*p.second-k+1)/2;
				st.pop();
				st.push({p.first,p.second-k});
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
