#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,n,cost=0,w,p,t;
	struct record{
		int price,time;
	};
	vector<record>sub;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>w>>p>>t;
		cost+=p;
		for(int j=0;j<sub.size();){
			if(sub[j].time+45<t)	sub.erase(sub.begin()+j);
			else break;
		}
		if(w){
			for(int j=0;j<sub.size();j++){
				if(sub[j].price>=p){
					cost-=p;sub.erase(sub.begin()+j);break;
				}
			}
		}
		else{
			sub.push_back({p,t});
		}
	}
	cout<<cost;
	return 0;
}
