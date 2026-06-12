#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,i,tt,pa[200007],pb[200007],qa[200007],qb[200007];
    if(!(cin>>t)) return 0;
    for(tt=1;tt<=t;tt++){
        if(!(cin>>n)) break;
        string s;
        if(!(cin>>s)) break;
        int aa=1,bb=1;
        for(i=1;i<=n;i++){
            if(s[i-1]=='a'){pa[aa]=i;qa[aa]=i-aa+1;aa++;}
            if(s[i-1]=='b'){pb[bb]=i;qb[bb]=i-bb+1;bb++;}
        }
        long long resa=0,resb=0;
        if(aa>1){int med=qa[(aa-1)/2+1];for(i=1;i<aa;i++) resa+=abs(qa[i]-med);}
        if(bb>1){int med=qb[(bb-1)/2+1];for(i=1;i<bb;i++) resb+=abs(qb[i]-med);}
        cout<<min(resa,resb)<<"\n";
    }
    return 0;
}
