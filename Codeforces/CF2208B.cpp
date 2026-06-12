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
	int n,k,p,m;
	cin>>n>>k>>p>>m;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int c=0,cnt=0;
	a[p]+=inf;
	deque<int>dq;
	for(int i=1;i<=n;i++)
		dq.push_back(a[i]);
	while(1){
		int fp=inf;
		for(int i=0;i<k;i++){
			if(dq[i]>=inf){
				fp=i;break;
			}
		}
		if(fp!=inf){
			if(c+dq[fp]-inf<=m){
				dq.push_back(dq[fp]);
				c+=dq[fp]-inf;
				dq.erase(dq.begin()+fp);				
				cnt++;
			}
			else break;
		}
		else{
			int mn=0;
			for(int i=0;i<k;i++){
				if(dq[i]<dq[mn])mn=i;
			}
			if(c+dq[mn]<=m){
				dq.push_back(dq[mn]);
				c+=dq[mn];
				dq.erase(dq.begin()+mn);				
			}
			else break;
		}
	}
	cout<<cnt<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
