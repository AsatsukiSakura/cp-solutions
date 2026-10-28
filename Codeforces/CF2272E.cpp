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
void calc(const string &a,const string &b,int x,int y){
	int fw=0;
	vector<int>wt;
	for(int i=1;i<=y;i++){
		if(b[i]=='W')wt.push_back(i);
	}
	vector<int>gaps;
	for(int i=1;i<wt.size();i++)
		gaps.push_back(wt[i]-wt[i-1]);
	int r=1;
	int ptr=0;
	int cnt=wt.size();
	sort(gaps.begin(),gaps.end());
	for(int i=1;i<=x;i++){
		r+=cnt;
		while(ptr<gaps.size()&&gaps[ptr]==i){
			ptr++;
			cnt--;
		}
		if(a[i]=='W')fw=i;
		else{
			if(fw){
				if(!wt.empty())cout<<max(fw+y,i-1+wt.back())-fw+1;
				else cout<<y+1;
			}else{
				cout<<r;
			}
			cout<<' ';
		}
		
	}
	cout<<'\n';
}
void solve(){
	string s,t;
	int n,m;
	cin>>n>>m>>s>>t;
	s=' '+s;
	t=' '+t;
	calc(s,t,n,m);
	calc(t,s,m,n);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
