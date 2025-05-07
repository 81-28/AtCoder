// https://atcoder.jp/contests/abc303/tasks/abc303_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) puts(x?"Yes":"No")
#define f first
#define s second
using ll=long long;
using pll=pair<ll,ll>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m,h,k;
    string st;
    cin >> n >> m >> h >> k >> st;
    pll pos={0,0};
    map<pll,bool> mp;
    pll p;
    rep(i,m) {
        cin >> p;
        mp[p]=1;
    }
    rep(i,n) {
        if (st[i]=='R') pos.f++;
        if (st[i]=='L') pos.f--;
        if (st[i]=='U') pos.s++;
        if (st[i]=='D') pos.s--;
        h--;
        if (h<0) {
            YesNo(0);
            return 0;
        }
        if (mp[pos]&&h<k) {
            mp[pos]=0;
            h=k;
        }
    }
    YesNo(1);

    return 0;
}
