#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
using ll=long long;
void solve(){
	int n,p;
	cin>>n>>p;
	ll score=0;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s=="UnreasonableProblemArrangement"){
			score+=10;continue;
		}
		char c=s.back();
		s.pop_back();
		if(mp.count(s)&&(c>='A')&&(c<='L')){
		
			score+=mp[s];
		}
	}
//	cerr<<score<<'\n';
	if(score>p){cout<<"Joker\n";}
	else cout<<"Judger\n";
}
int main(){

		mp["WrongProblem"]=100;
		mp["SameProblem"]=	30;
		//mp["UnreasonableProblemArrangement"]=10;
		mp["UnreasonableLimitForProblem"]=5;
		mp["WeakTestsForProblem"]=3;
		mp["BadProblem"]=1;
	int T ;cin>>T;
	for(int i=1;i<=T;i++)solve();
}
