// https://atcoder.jp/contests/abc476/tasks/abc476_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    multiset<int> s;
    rep(i,2) s.insert(a[i]);
    for (int i=2; i<n; ++i) {
        s.insert(a[i]);
        if (s.size()>3) s.erase(s.begin());
        print(*s.begin());
    }

    return 0;
}
