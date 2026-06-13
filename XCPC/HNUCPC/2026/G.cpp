#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mx=1e9;
int main(){
	int n;
	int cnt=0;
	cin>>n;
	vector<int>x(n+1);
	for(int i=1;i<=n;i++)
		cin>>x[i];
	set<int>s;
	for(int i=1;i*(i+1)<=mx;i++){
		ll tmp=i;
		for(int j=i+1;;j++){
			tmp*=j;
		//	cnt++;
			if(tmp>mx)break;
			s.insert(tmp);
			//cnt+=log2(s.size());
		}
	}
	for(int i=1;i<=n;i++){
		cout<<(s.count(x[i])?"YES\n":"NO\n");
	}
	//cout<<cnt;
	return 0;
}
