// https://atcoder.jp/contests/abc349/tasks/abc349_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// [l,r): 求める対象の区間, [a,b): 現在の区間
v<pii> query(const int& l,const int& r,const int& a,const int& b) {
    if (r<=a||b<=l) return {}; // 一切重ならない場合
    if (l<=a&&b<=r) return {{a,b}}; // 完全に含まれる場合
    // 現在の区間内に境目(l||r)が存在する場合、子の最大値を求める
    int m=(a+b)/2;
    v<pii> ql=query(l,r,a,m);
    v<pii> qr=query(l,r,m,b);
    for (auto p:qr) ql.pb(p);
    return ql;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int l,r;
    cin >> l >> r;
    v<pii> p=query(l,r,0,1LL<<60);
    int n=p.size();
    print(n);
    rep(i,n) print(p[i]);

    return 0;
}
