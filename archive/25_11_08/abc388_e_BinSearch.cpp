// https://atcoder.jp/contests/abc388/tasks/abc388_e

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


int n;
vi a;
bool check(const int& k) {
    rep(i,k) {
        if (a[i]*2>a[n-k+i]) return 0;
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    a=vi(n);
    cin >> a;
    // [l,r)
    int l=0,r=n/2+1;
    while (l+1<r) {
        int m=(l+r)/2;
        if (check(m)) l=m;
        else r=m;
    }
    print(l);

    return 0;
}
