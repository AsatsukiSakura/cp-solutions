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
	ll n;
	cin>>n;
	set<ll>s2,s3;
	ll tp=1;
	while(tp<=2e18){
		s2.insert(tp);
		ll tmp=tp;
		while(tmp<=2e18){
			s3.insert(tmp);
			tmp*=3;
		}
		tp*=2;
	}
	vector<ll>dp;
	dp.push_back(1);
	while(dp.back()<=1e18){
		dp.push_back(1+min(2**s2.lower_bound(dp.back()),3**s3.lower_bound(dp.back()))/2);
	}
	auto it=upper_bound(dp.begin(),dp.end(),n);
	cout<<it-dp.begin()-1;
	return 0;
}
