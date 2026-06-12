#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<int>s;
	int m;cin>>m;
	for(int i=1;i<=m;i++){
		int o,l;
		cin>>o>>l;
		if(o==1){
			if(s.count(l)){
				cout<<"Already Exist"<<endl;
			}
			else{
				s.insert(l);
			}
		}
		if(o==2){
			if(s.empty()){
				cout<<"Empty"<<endl;
			}
			else{
				auto it=s.lower_bound(l);
				if(it==s.end()){
					cout<<*prev(it)<<endl;
					s.erase(prev(it));
				}
				else if(it==s.begin()){
					cout<<*it<<endl;
					s.erase(it);
				}
				else{
					if(abs(*it-l)<=abs(*prev(it)-l)){
						cout<<*it<<endl;
						s.erase(it);
					}
					else{
						cout<<*prev(it)<<endl;
						s.erase(prev(it));
					}
				}
			}
		}
	}
	return 0;
}
