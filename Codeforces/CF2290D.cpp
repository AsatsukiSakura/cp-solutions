#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=' '+s;
	vector<bool>b(25,0);
	for(int i=1,j=n;i<=j;i++,j--){
		if(s[i]!=s[j]){
			if(s[j]<s[i])swap(s[i],s[j]);
			for(char c=s[i];c<s[j];c++){
				b[c-'a']=1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=24;i++)ans+=b[i];
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
