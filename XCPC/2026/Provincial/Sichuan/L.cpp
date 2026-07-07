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
	string s;
	cin>>s;
	int n=s.length();
	s=' '+s;
	vector<int>nll(n+1,0),nlr(n+1,n+1);
	vector<int>ngl(n+1,0),ngr(n+1,n+1);
	stack<int>st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&s[st.top()]>=s[i]) st.pop();
		nll[i]=st.empty()?0:st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&s[st.top()]>=s[i]) st.pop();
		nlr[i]=st.empty()?n+1:st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=1;i<=n;i++){
		while(!st.empty()&&s[st.top()]<=s[i]) st.pop();
		ngl[i]=st.empty()?0:st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&s[st.top()]<=s[i]) st.pop();
		ngr[i]=st.empty()?n+1:st.top();
		st.push(i);
	}
	int i=1,j=n;
	string b="";
	while(1){
		if(i==j){b+=s[i];break;}
		else if(s[i]<s[j])b+=s[i++];
		else if(s[i]>s[j])b+=s[j--];
		else if(s[i]==s[j]){
			if(j==i+1){b+=s[i++],b+=s[j--];break;}
			if((nll[j]!=0 && nll[j]>i) || (nlr[i]!=n+1 && nlr[i]<j)){
				b+=s[i++],j--;
			}else if((ngl[j]!=0 && ngl[j]>i) || (ngr[j]!=n+1&&ngr[i]<j)){
				b+=s[i++],b+=s[j--];
			}
			else b+=s[i++],j--;
		}
	}
	cout<<b<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
