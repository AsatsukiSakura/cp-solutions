#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct point {
    ll x,y;
};
const ll inf =0x3f3f3f3f;
void solve() {
    ll n,p,q;
    cin>>n>>p>>q;
    vector<point>a(n+1);
    for (ll i=1;i<=n;i++) {
        cin>>a[i].x>>a[i].y;
    }
    ll ans=1ll*(p+1)*(q+1)*(p+q)/2;
    auto cmp=[](point a,point b) {
        if (a.x<b.x) return true;
        if (a.x>b.x) return false;
        else return a.y>b.y;
    };
    sort(a.begin()+1,a.end(),cmp);
    vector<ll>yp(n+1,0);
    for (ll i=1;i<=n;i++) {
        yp[i]=a[i].y;
    }
    vector<ll>lmin(n+1,inf),lis(n+1,0);
    lmin[0]=-1;
    for (ll i=1;i<=n;i++) {
        ll idx=upper_bound(lmin.begin()+1,lmin.end(),yp[i])-lmin.begin();
        lmin[idx]=yp[i];
        lis[i]=idx;
    }
    vector<vector<point>>lp(n+1);
    for (int i=1;i<=n;i++) {
        if (a[i].x<=p && a[i].y<=q)
        lp[lis[i]].push_back({a[i].x+1,a[i].y+1});
    }
    for (int i=1;i<=n;i++) {
        lp[i].push_back({0,q+1});
        sort(lp[i].begin(),lp[i].end(),cmp);
    }
    for (int i=n;i>=1;i--) {
        if (lp[i].size()==1)continue;;
        for (int j=1;j<lp[i].size();j++) {
            ans-=1ll*(lp[i][j-1].y-lp[i][j].y)*(p+1-lp[i][j].x);
        }
    }
    cout<<ans<<endl;
}
int main() {
    ll t;
    cin>>t;
    while (t--)solve();
}
