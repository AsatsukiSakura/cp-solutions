#include<bits/stdc++.h>
using namespace std;
bool isNoise(const string& s) {
	if (s.length()==5&&s[2]=='-')return true;
	if (s.length()==8&&s[2]==':'&&s[5]==':')return true;
	if (s.find("<img") != string::npos ||s.find("nt_qq") != string::npos||s.find("src=") != string::npos || s == "/>") return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	map<string,int>m;
	while(cin>>s&&s!="---"){
	if(!isNoise(s))	m[s]++;
	}
	vector<pair<string,int>>v(m.begin(),m.end());
	using psi=pair<string,int>;
	auto cmp=[](psi a,psi b){
		return a.second>b.second;
	};
	sort(v.begin(),v.end(),cmp);
	for(psi p:v){
		if(p.second<2)break;
		cout<<p.first<<' '<<p.second<<endl;
		cout<<endl;
	}
	return 0;
}
