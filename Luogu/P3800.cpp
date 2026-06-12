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
	int n,m,k,t;
	cin>>n>>m>>k>>t;
	vector<vector<int>>v(n+1,vector<int>(m+1,0));
	for(int i=1;i<=k;i++){
		int x,y,v_;
		cin>>x>>y>>v_;
		v[x][y]=v_;
	}
	vector<int>dp(m+1,0),tmp(m+1,0);
	deque<int>dq;
	for(int i=1;i<=m;i++){
		dp[i]=v[1][i];
	}
	for(int i=2;i<=n;i++){
		dq.clear();
		tmp.assign(m+1,0);
		for(int j=1-t;j<=m;j++){
			
			while(!dq.empty()&&dq.front()<j-t){
				dq.pop_front();
			}
			if(j+t<=m){
				while(!dq.empty()&&dp[dq.back()]<=dp[j+t]){
					dq.pop_back();
				}
				dq.push_back(j+t);
			}
			if(!dq.empty()&&j>=1){
				tmp[j]=dp[dq.front()]+v[i][j];
			}
		}
		
		
		dp=tmp;
	}
	cout<<*max_element(dp.begin()+1,dp.end());
	return 0;
}

