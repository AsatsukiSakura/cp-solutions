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
	vector<int>l(n+1),r(n+1);
	vector<vector<vector<int>>>v(2,vector<vector<int>>(2*n+1));
	vector<int>s(2*n+1,0);
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		if(l[i]==r[i])s[l[i]]++;
		else{ 
			v[0][l[i]].push_back(r[i]);
			v[1][r[i]].push_back(l[i]);
		}
	}
	for(int i=1;i<=2*n;i++){
		sort(v[0][i].begin(),v[0][i].end());
		sort(v[1][i].begin(),v[1][i].end());
	}
	const int sqn=max(1,(int)sqrt(n)*2);
	vector<vector<int>>idx(2,vector<int>(2*n+1,-1));
	vector<vector<int>>pre,suf;
	for(int i=1;i<=2*n;i++){
		if(v[0][i].size()>=sqn){
			idx[0][i]=pre.size();
			vector<int>p(2*n+1,0);
			for(int rval:v[0][i])
				p[rval]++;
			for(int k=i+1;k<=2*n;k++)
				p[k]+=p[k-1];
			pre.push_back(p);
		}
		if(v[1][i].size()>=sqn){
			idx[1][i]=suf.size();
			vector<int>sf(2*n+1,0);
			for(int lval:v[1][i])
				sf[lval]++;
			for(int k=i-1;k>=1;k--)
				sf[k]+=sf[k+1];
			suf.push_back(sf);
		}
	}
	auto W=[&](int x,int y){
		int ans=0,cnt=0;
		if(v[0][x].size()>=v[1][y].size()&&v[0][x].size()>=sqn){
			ans=pre[idx[0][x]][y-1];
			for(int i=0;i<v[1][y].size();i++){
				int lval=v[1][y][i];
				if(lval==x)cnt++;
				else if(lval>x)
					ans=max(ans,pre[idx[0][x]][lval]+(int)v[1][y].size()-i);
			}
		}else if(v[1][y].size()>=sqn){
			ans=suf[idx[1][y]][x+1];
			for(int i=0;i<v[0][x].size();i++){
				int rval=v[0][x][i];
				if(rval==y)cnt++;
				else if(rval<y)
					ans=max(ans,i+1+suf[idx[1][y]][rval]);
			}
		}else{
			int j=0;
			for(int i=0;i<v[1][y].size();i++){
				int lval=v[1][y][i];
				if(lval==x)cnt++;
				else if(lval>x){
					while(j<v[0][x].size()&&v[0][x][j]<=lval)
						j++;
				ans=max(ans,j+(int)v[1][y].size()-i);
				}
			}
			while(j<v[0][x].size()&&v[0][x][j]<y)
				j++;
			ans=max(ans,j);
		}
		return cnt+ans;
	};
	vector<int>dp(2*n+1,0);
	for(int i=1;i<=2*n;i++){
		dp[i]=dp[i-1]+s[i];
		int lst=-1;
		for(int j:v[1][i]){
			if(j==lst)continue;
			lst=j;
			dp[i]=max(dp[i],dp[j]+W(j,i)+s[i]);
		}
	}
	cout<<dp[2*n]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
