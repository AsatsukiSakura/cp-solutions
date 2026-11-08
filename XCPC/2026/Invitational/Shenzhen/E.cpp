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
const int N=300010;
char a[N],b[N];
void solve(){
	priority_queue<int,vector<int>,greater<int>> a1,a2,b1,b2;
	int n;
	int c;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	cin>>c;
	int min1=0,min2=0,max1=0,max2=0;
	int fmin1=inf,fmax1=0,fmin2=inf,fmax2=0;
	for(int i=1;i<=n;i++){
		if(a[i]!='0'){
			if(a[i]=='1')fmin1=min(fmin1,i);
			if(a[i]=='2')fmin2=min(fmin2,i);
			if(i<c){
//				fmin1=min(fmin1,i);
				if(a[i]=='1')min1++;
				if(a[i]=='2')a2.push(i);
			}
			else{
				if(a[i]=='1')a1.push(i);
				if(a[i]=='2')a2.push(i);
			}
		}
		if(b[i]!='0'){
			if(b[i]=='1')fmax1=max(fmax1,i);
			if(b[i]=='2')fmax2=max(fmax2,i);
			if(i<c){
				if(b[i]=='1')min2++;
				if(b[i]=='2')b2.push(i);
			}
			else{
				if(b[i]=='1')b1.push(i);
				if(b[i]=='2')b2.push(i);
			}
		}
	}
//	cout<<"min"<<min1<<" "<<min2<<"\n";
	if(min1==0){
		cout<<"Yes\n";
		return ;
	}
//	if(min2==0)
	if(min2<=1){
		if(fmin2<fmax2){
			cout<<"Yes\n";
			return ;
		}
		if(fmin1<fmax1&&fmax1>=c){
			cout<<"Yes\n";
			return ;
		}
		if(fmin1<fmax1&&fmax2==0){
			cout<<"Yes\n";
			return ;
		}
		
	}
	for(int i=1;i<=n;i++){
		min1--;
		if(min1==0){
			cout<<"Yes\n";
			return ;
		}
		if(b1.empty()){
			cout<<"No\n";
			return ;
		}
		if(!b1.empty()){
			int now=b1.top();
			int id=0;
			b1.pop();
			while(!a1.empty()){
				if(a1.top()>now){
					id=1;
					a1.pop();
					break;
				}
				a1.pop();
			}
			if(id==1)continue;
		}
		if(!b2.empty()){
			int now=b2.top();
			int id=0;
			b2.pop();
			while(!a2.empty()){
				if(a2.top()>now){
					id=1;
					a2.pop();
					break;
				}
				a2.pop();
			}
			if(id==1)continue;
		}
		cout<<"No\n";
		return ;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
