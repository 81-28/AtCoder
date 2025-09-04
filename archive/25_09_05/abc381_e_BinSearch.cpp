// https://atcoder.jp/contests/abc381/tasks/abc381_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


string s;
vvi idx(3);
// 範囲[l,r]に長さ2n+1の11/22文字列が存在するかどうか
bool check(const int& l,const int& r,const int& n) {
    if (n) {
        auto itl=lower_bound(all(idx[0]),l);
        auto itr=upper_bound(all(idx[0]),r);
        int d=itr-itl;
        if (d<n) return 0;
        itl+=n-1;
        int t=*itl;
        itl=upper_bound(all(idx[1]),t);
        itr=upper_bound(all(idx[1]),r);
        d=itr-itl;
        if (itl==itr) return 0;
        t=*itl;
        itl=upper_bound(all(idx[2]),t);
        itr=upper_bound(all(idx[2]),r);
        d=itr-itl;
        return d>=n;
    } else {
        auto itl=lower_bound(all(idx[1]),l);
        auto itr=upper_bound(all(idx[1]),r);
        return itl!=itr;
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q >> s;
    rep(i,n) {
        if (s[i]=='1') idx[0].pb(i);
        if (s[i]=='/') idx[1].pb(i);
        if (s[i]=='2') idx[2].pb(i);
    }
    while (q--) {
        int l,r;
        cin >> l >> r;
        --l,--r;
        if (!check(l,r,0)) {
            print(0);
            continue;
        }
        // 範囲[b,t)
        int b=0,t=(r-l)/2+1;
        while (b+1<t) {
            int m=(b+t)/2;
            if (check(l,r,m)) b=m;
            else t=m;
        }
        print(b*2+1);
    }

    return 0;
}
