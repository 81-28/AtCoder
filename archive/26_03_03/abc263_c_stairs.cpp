// https://atcoder.jp/contests/abc263/tasks/abc263_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n);
    rep(i,n) a[i]=i+1;
    while (1) {
        print(a);
        int l=n-1;
        for (; l>=0; --l) {
            if (++a[l]<=m-(n-1-l)) break;
        }
        if (l<0) break;
        for (int i=l; i+1<n; ++i) a[i+1]=a[i]+1;
    }

    return 0;
}
