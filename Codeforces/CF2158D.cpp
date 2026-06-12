#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<'='<<x<<endl
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
vector<pii> str0(string a){
	int n=a.size()-1;
	vector<pii>ans;
	bool b=false;
	pii p={0,0};
	int l=1,r=1;
	for(int i=1;i<=n-1;i++){
		if(a[i]==a[i+1]){
			r=i+1;
		}
		else{
			l=i+1;
			r=i+1;
		}
		if(r-l>p.second-p.first){
			p={l,r};
		}
	}
	if(p==pii{0,0}){
		ans.push_back({1,3});
		p={3,4};
		a[1]=((a[1]-'0')^1)+'0';
		a[2]=((a[2]-'0')^1)+'0';
		a[3]=((a[3]-'0')^1)+'0';
	}
	ans.push_back(p);
	l=p.first;
	r=p.second;
	int state=a[l]-'0';
	debug(l);debug(r);debug(state);
	while(l>1 || r<n){
	//	debug(l);
	//	debug(r);
		l--;r++;
		while(l>0 && a[l]-'0'!=state){
			l--;
		}
		while(r<n+1 && a[r]-'0'!=state){
			r++;
		}
		ans.push_back({++l,--r});
		
		state^=1;
	}
	if(state)ans.push_back({1,n});
	return ans;
}
string operator~(string a){
	string str=" ";
	for(int i=1;i<=a.size()-1;i++){
		if(a[i]=='1')str.push_back('0');
		if(a[i]=='0')str.push_back('1');
	}
	return str;
}
void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	a=' '+a; 
	b=' '+b;
	if(a==b){
		cout<<0<<endl;return;
	}
	if(n==2&&(a==" 01"|| a==" 10")){
		cout<<-1<<endl; return;
	}
	if(n==3&&(a==" 010"||b==" 010"||a==" 101"||b==" 101")){
		if(a==(~b)){
			cout<<1<<endl<<1<<' '<<3<<endl;
			return;
		}
		else {
			cout<<-1<<endl;return;
		}
	}
	vector<pii>ansa,ansb;
	ansa=str0(a);
	ansb=str0(b);
	cout<<ansa.size()+ansb.size()<<endl;
	for(auto it=ansa.begin();it!=ansa.end();it++){
		cout<<(*it).first<<' '<<(*it).second<<endl;
	}
	for(auto it=ansb.rbegin();it!=ansb.rend();it++){
		cout<<(*it).first<<' '<<(*it).second<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
/*
2
4
1110
0110
5
10101
00000
*/
