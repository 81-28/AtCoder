// https://atcoder.jp/contests/abc271/tasks/abc271_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vvi a(n);
    rep(i,n) {
        int l;
        cin >> l;
        a[i]=vi(l);
        cin >> a[i];
    }
    while (q--) {
        int s,t;
        cin >> s >> t;
        print(a[--s][--t]);
    }

    return 0;
}
