// https://atcoder.jp/contests/abc463/tasks/abc463_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<tuple<int,int,int>> t;
    multiset<int> s;
    rep(i,n) {
        int h,l;
        cin >> h >> l;
        s.insert(h);
        t.pb({l,0,h});
    }
    int q;
    cin >> q;
    rep(i,q) {
        int m;
        cin >> m;
        t.pb({m,1,i});
    }
    sort(all(t));

    vi ans(q);
    for (auto[l,m,h]:t) {
        if (m) ans[h]=*s.rbegin();
        else s.erase(s.find(h));
    }
    for (int val:ans) print(val);

    return 0;
}
