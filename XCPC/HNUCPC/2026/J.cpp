#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ll a,b;
	cin>>a>>b;
	if(abs(a-b)%3==0)cout<<abs(a-b)/3;
	else cout<<-1;
	return 0;
}
