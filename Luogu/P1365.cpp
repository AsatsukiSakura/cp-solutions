#include<bits/stdc++.h>
using namespace std;
int main()
{
    	double score=0,cb=0;
    	int length,i;
    	string hit;
    	cin>>length>>hit;
    	for(i=1;i<=length;i++){
    	    if(hit[i-1]=='o'){ score=score+2*cb+1;cb+=1;}
    	    if(hit[i-1]=='x') cb=0;
    	    if(hit[i-1]=='?'){ score=score+cb+0.5;cb=cb/2+0.5;}
    	}
    	printf("%.4lf",score);
    	return 0;
}