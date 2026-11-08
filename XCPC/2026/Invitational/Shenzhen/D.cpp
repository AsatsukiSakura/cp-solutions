#include<bits/stdc++.h>
using namespace std;
#define int long long
char op[200005];
int x[200005];
int r[200005];
void work(){
	int n;
	cin>>n;
	int last_w=-1;
	for(int i=1;i<=n+1;i++){
		if(i<=n)
			cin>>op[i];
		else
			op[i]='W';
		if(op[i]=='F'){
			cin>>x[i];
		}else{
			r[i]=i+1;
			if(last_w!=-1){
				r[last_w]=i;
			}
			last_w=i;
		}
	}
	int workers=0;
	priority_queue<int> idle;
	priority_queue<int,vector<int>,greater<int>> working;
	int profit=0,ans=0;
	for(int i=1;i<=n;i++){
		if(op[i]=='F'){
			if(!working.empty()){
				if(working.top()<x[i]){
					idle.push(working.top());
					
					profit-=working.top();
					working.pop();
					
					working.push(x[i]);
					profit+=x[i];
				}else{
					idle.push(x[i]);
				}
			}else{
				idle.push(x[i]);
			}
		}else{
			workers++;
			while(workers>0){
				if(idle.empty()){
					working.push(0);
				}else{
					working.push(idle.top());
					profit+=idle.top();
					idle.pop();
				}
				workers--;
			}
			
			struct node{
				int x,part;
				bool operator<(const node&b)const{
					return x*part<b.x*b.part;
				}
			};
			priority_queue<node> newf;
			for(int j=i+1;j<r[i];j++){
				newf.push({x[j],(r[i]-j)});
			}
			
			vector<int> poped;
			int curprofit=profit*(r[i]-i);
			while(!newf.empty()&&!working.empty()
				  &&newf.top().x*newf.top().part>working.top()*(r[i]-i)){
				curprofit-=working.top()*(r[i]-i);
				curprofit+=newf.top().x*newf.top().part;
				poped.push_back(working.top());
				working.pop();
				newf.pop();
			}
//			cout<<"cur "<<(r[i]-i)<<endl;
			ans+=curprofit;
			for(auto p:poped){
				working.push(p);
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		work();
	}
	return 0;
}
