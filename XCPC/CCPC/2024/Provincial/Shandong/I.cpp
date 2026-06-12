#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		int d=0;
		for(;d<=n-1;d++){
			if(s[d]==s[(n-1+d)%n]){
				break;
			}
		}
		cout<<(d==n?-1:d)<<'\n';
	}
}
