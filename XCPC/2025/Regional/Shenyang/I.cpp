#include<bits/stdc++.h>
using namespace std;
bool sol[505][55];
int cnt[505];
int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b,c;
		cin>>a>>b>>c;
		if(!sol[a][b]){
			sol[a][b]=1;
			cnt[a]++;
			if(c<240){
				cout<<b<<endl;
			}else if(cnt[a]<=3){
				cout<<b<<endl;
			}else{
				cout<<0<<endl;
			}
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
