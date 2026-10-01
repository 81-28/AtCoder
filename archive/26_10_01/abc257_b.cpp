// https://atcoder.jp/contests/abc257/tasks/abc257_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k,q;
    cin >> n >> k >> q;
    vi a(k);
    cin >> a;
    while (q--) {
        int l;
        cin >> l;
        --l;
        if (a[l]==n) continue;
        if (l+1<n && a[l+1]==a[l]+1) continue;
        ++a[l];
    }
    print(a);

    return 0;
}
