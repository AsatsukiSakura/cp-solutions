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
struct point{
	int pos,dir,dis;
};
bool operator<(const point &a,const point &b){
	return a.dis<b.dis;
}
void solve(){
	priority_queue<point>pq;
	map<int,int>m;
	int n,k,x;
	cin>>n>>k>>x;
	vector<int>a(n+1),res;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!m.count(a[i])){
			pq.push(point{a[i],0,0});
			m[a[i]]=1;
		}
	}
	sort(a.begin()+1,a.end());
	if(a[1]!=0)pq.push({0,1,a[1]});
	if(a[n]!=x)pq.push({x,-1,x-a[n]});
	for(int i=1;i<=n-1;i++){
		int l=a[i+1]-a[i];
		if(l>=2){
			if(l==2){
				pq.push({a[i]+l/2,1,1});
			}
			else{
				pq.push({a[i]+l/2,-1,l/2});
				pq.push({a[i]+1+l/2,1,a[i+1]-(a[i]+1+l/2)});
			}
		}
	}
	for(int i=1;i<=k;i++){
		auto[pos,dir,dis]=pq.top();
		pq.pop();
		if(dir==0)res.push_back(pos);
		else{
			res.push_back(pos);
			if(dis>1){
				pq.push({pos+dir,dir,dis-1});
			}
		}
	}
	sort(res.begin(),res.end());
	for(int y:res){
		cout<<y<<' ';
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
