#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
#define int long long
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
bool cmp(const int &a,const int &b){
	return a>b;
}
void solve(){
	int n;
	cin>>n;
	vector<int>odd,even;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x&1)odd.push_back(x);
		else {
			even.push_back(x);
		}
	}
	
//	debug(odd.size());
	if(odd.size()==0){
		for(int i=1;i<=n;i++){
			cout<<0<<' ';
		}
		cout<<endl;return;
	}
	sort(odd.begin(),odd.end(),cmp);
	if(even.size()==0){
		for(int i=1;i<=n;i++){
			if(i&1)cout<<odd[0]<<' ';
			else cout<<0<<' ';
		}
		cout<<endl;return;
	}
	sort(even.begin(),even.end(),cmp);
	vector<ll>esm(even.size()+1,0);
	partial_sum(even.begin(),even.end(),esm.begin()+1);
	for(int i=1,j=0;i<=n;i++){
		if(i==n&&odd.size()%2==0)cout<<0<<' ';
		else	cout<<odd[0]+esm[j]<<' ';
		if(j+1==esm.size())	j--;
		else j++;
	}
	cout<<endl;return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
