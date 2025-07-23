// https://atcoder.jp/contests/abc330/tasks/abc330_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    map<int,int> m;
    set<int> s;
    // mexは0~n
    rep(i,n+1) s.insert(i);
    rep(i,n) {
        if (a[i]<=n && m[a[i]]==0) s.erase(a[i]);
        ++m[a[i]];
    }
    while (q--) {
        int i,x;
        cin >> i >> x;
        --i;
        --m[a[i]];
        if (a[i]<=n && m[a[i]]==0) s.insert(a[i]);
        a[i]=x;
        if (a[i]<=n && m[a[i]]==0) s.erase(a[i]);
        ++m[a[i]];
        print(*s.begin());
    }

    return 0;
}
