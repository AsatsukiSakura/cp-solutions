#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x,i=0;
	vector<int> digit(100,0x3f);
	cin>>x;digit[0]=0;
	while(x!=0){
		digit[i]=x&1;
		x>>=1;i++;
	}int d=i-1;
	int cnt=0;
	for(int num:digit){
		if(num==0)	cnt++;
		else break;
	}
	for(i=d+1;i<=d+cnt;i++){
		digit[i]=0;
	}
	d+=cnt;
	for(i=0;i<=d;i++){
		if(digit[i]!=digit[d-i] || ((i==d-i)&&digit[i]==1)){
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
	return;
}
int main(){
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
