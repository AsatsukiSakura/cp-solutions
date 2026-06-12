#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
void solve(){
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'){
			cnt++;
			for(int j=i-1;j>=1&&j>=i-k+1;j--){
				if(s[j-1]=='1'){
					cnt--;break;
				}
			}
		}
	}
	cout<<cnt<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
