// https://atcoder.jp/contests/abc403/tasks/abc403_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) puts(x?"Yes":"No")
using ll=long long;


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m,q;
    cin >> n >> m >> q;
    map<ll,bool> op;
    map<ll,map<ll,bool>> mp;
    ll a,x,y;
    rep(i,q) {
        cin >> a >> x;
        if (a==1) {
            cin >> y;
            mp[x][y]=1;
        }
        if (a==2) op[x]=1;
        if (a==3) {
            cin >> y;
            if (op[x]) YesNo(1);
            else if (mp[x][y]) YesNo(1);
            else YesNo(0);
        }
    }

    return 0;
}
