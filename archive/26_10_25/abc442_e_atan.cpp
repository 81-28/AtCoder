// https://atcoder.jp/contests/abc442/tasks/abc442_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using ld=long double;
const ld PI=acosl(-1);
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


pii norm(const pii& p) {
    int g=gcd(p.first,p.second);
    return {p.first/g,p.second/g};
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<pii> p(n);
    map<pii,int> cnt,pref;
    for (pii& a:p) {
        cin >> a.first >> a.second;
        a=norm(a);
        ++cnt[a];
    }

    v<pair<ld,pii>> ang;
    for (auto[a,c]:cnt) {
        ld t=atan2l(a.second,a.first);
        if (t<0) t+=2*PI;
        ang.push_back({t,a});
    }
    sort(all(ang));

    int sum=0;
    for (auto[t,a]:ang) pref[a]=(sum+=cnt[a]);

    while (q--) {
        int a,b;
        cin >> a >> b;
        --a;--b;
        int sa=pref[p[a]],sb=pref[p[b]];
        print(sa-sb+cnt[p[b]]+(sa<sb ? n:0));
    }

    return 0;
}
