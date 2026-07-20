// https://atcoder.jp/contests/abc195/tasks/abc195_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rall(v) v.rbegin(),v.rend()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,q;
    cin >> n >> m >> q;
    v<pii> p(n);
    for (auto&[v,w]:p) cin >> w >> v;
    sort(rall(p));
    vi x(m);
    cin >> x;
    while (q--) {
        int l,r;
        cin >> l >> r;
        multiset<int> s;
        for (int i=0; i<l-1; ++i) s.insert(x[i]);
        for (int i=r; i<m; ++i) s.insert(x[i]);
        int ans=0;
        for (auto[v,w]:p) {
            auto it=s.lower_bound(w);
            if (it==s.end()) continue;
            ans+=v;
            s.erase(it);
        }
        print(ans);
    }

    return 0;
}
