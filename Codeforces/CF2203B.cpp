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
	ll x;
	cin>>x;
	vector<int>a;
	int sum=0;
	while(x){
		a.push_back(x%10);
		sum+=x%10;
		x/=10;
	}
	a.back()--;
	sort(a.begin(),a.end(),greater<int>());
	int cnt=0;
	for(int &d:a){
		debug(d);debug(sum);
		if(sum<=9){
			cout<<cnt<<'\n';
			return;
		}
		sum-=d;
		cnt++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
