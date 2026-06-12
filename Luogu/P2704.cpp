#include<bits/stdc++.h>
using namespace std; 

int main() {
	int cnt=0;
	for(int i=1;i<=1023;i++)
	if(((i>>1)&i)==0 &&((i>>2)&i)==0){
		cnt++;
		cout<<i<<' ';
		for(int j=i;j>=1;j>>=1)	cout<<(1&j);
		cout<<endl;
	}cout<<cnt;}
	


