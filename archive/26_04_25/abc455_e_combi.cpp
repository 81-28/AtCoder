// https://atcoder.jp/contests/abc455/tasks/abc455_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    // {{aに対してのb,cの数},idx}
    map<pii,vi> m;
    // aa[i]:cに対してのbの数がiであるidx
    map<int,vi> aa,bb,cc;
    int a=0,b=0,c=0;
    m[{b-a,c-a}].pb(0);
    aa[b-c].pb(0);
    bb[c-a].pb(0);
    cc[a-b].pb(0);
    rep(i,n) {
        if (s[i]=='A') ++a;
        if (s[i]=='B') ++b;
        if (s[i]=='C') ++c;
        m[{b-a,c-a}].pb(i+1);
        aa[b-c].pb(i+1);
        bb[c-a].pb(i+1);
        cc[a-b].pb(i+1);
    }
    // 相異ならない場合を全体から除く
    int res=0;
    // 2つが一致
    for (auto[val,vec]:aa) {
        int l=vec.size();
        res+=l*(l-1)/2;
    }
    for (auto[val,vec]:bb) {
        int l=vec.size();
        res+=l*(l-1)/2;
    }
    for (auto[val,vec]:cc) {
        int l=vec.size();
        res+=l*(l-1)/2;
    }
    // 3つが一致
    for (auto[p,vec]:m) {
        int l=vec.size();
        res-=l*(l-1);
    }
    int sm=n*(n+1)/2;
    print(sm-res);

    return 0;
}
