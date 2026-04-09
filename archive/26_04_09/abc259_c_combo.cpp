// https://atcoder.jp/contests/abc259/tasks/abc259_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    int n=s.size(),m=t.size();
    // {文字,数}
    v<pii> p,q;
    int cmb=1;
    rep(i,n-1) {
        if (s[i]!=s[i+1]) {
            p.pb({s[i]-'a',cmb});
            cmb=0;
        }
        ++cmb;
    }
    p.pb({s[n-1]-'a',cmb});
    cmb=1;
    rep(i,m-1) {
        if (t[i]!=t[i+1]) {
            q.pb({t[i]-'a',cmb});
            cmb=0;
        }
        ++cmb;
    }
    q.pb({t[m-1]-'a',cmb});
    if (p.size()!=q.size()) {
        YesNo(0);
        return 0;
    }
    int l=p.size();
    rep(i,l) {
        auto[c,a]=p[i];
        auto[d,b]=q[i];
        if (c!=d) {
            YesNo(0);
            return 0;
        }
        if (a>b || (a==1&&b!=1)) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
