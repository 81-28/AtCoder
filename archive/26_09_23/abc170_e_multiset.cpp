// https://atcoder.jp/contests/abc170/tasks/abc170_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<multiset<int>> m(2e5+1);
    v<pii> p(n);
    for (auto&[a,b]:p) {
        cin >> a >> b;
        m[b].insert(a);
    }
    multiset<int> s;
    for (auto st:m) {
        if (st.empty()) continue;
        s.insert(*st.rbegin());
    }
    while (q--) {
        int c,d;
        cin >> c >> d;
        auto&[a,b]=p[--c];
        s.erase(s.find(*m[b].rbegin()));
        m[b].erase(m[b].find(a));
        if (m[b].size()) s.insert(*m[b].rbegin());
        b=d;
        if (m[b].size()) s.erase(s.find(*m[b].rbegin()));
        m[b].insert(a);
        s.insert(*m[b].rbegin());
        print(*s.begin());
    }

    return 0;
}
