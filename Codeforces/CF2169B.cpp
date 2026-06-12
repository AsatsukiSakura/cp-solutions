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
void solve(){
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<1<<endl;return;
	}
	int stc=0;
	for(int i=0;i<s.size();i++){
		stc+=(s[i]=='*');
		if(s[i]=='>'&&i+1<s.size()&&s[i+1]=='<'){
			cout<<-1<<endl;return;
		}
	}
	if(stc>=2){
		cout<<-1<<endl;return;
	}
	else{
		for(int i=0;i<s.size();i++){
			if(s[i]=='*'){
				if(i+1<s.size()&&s[i+1]=='<'){
					cout<<-1<<endl;return;
				}
				if(i-1<s.size()&&s[i-1]=='>'){
					cout<<-1<<endl;return;
				}
			}
		}
	}
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='<')cnt++;
		else break;
	}
	cout<<max(cnt+stc,(int)s.size()-cnt)<<endl;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
