#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int ask(vector<int>x){
	int res;
	cout<<"? "<<x.size();
	for(int i:x){
		cout<<' '<<i;
	}
	cout<<endl;
	cin>>res;
	return res;
}
void solve(){
	int n,j;
	cin>>n;
	vector<int>a;
	vector<int>ans(2*n+1,0);
	a.push_back(1);
	for(int i=2;i<=2*n;i++){
		a.push_back(i);
		j=ask(a);
		if(j){
			ans[i]=j;
			a.pop_back();
		}
	}
	a.clear();
	for(int i=1;i<=2*n;i++){
		if(ans[i]!=0)
			a.push_back(i);
	}
	for(int i=1;i<=2*n;i++){
		if(ans[i]==0){
			a.push_back(i);
			ans[i]=ask(a);
			a.pop_back();
		}
	}
	cout<<'!';
	for(int i=1;i<=2*n;i++){
		cout<<' '<<ans[i];
	}
	cout<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
