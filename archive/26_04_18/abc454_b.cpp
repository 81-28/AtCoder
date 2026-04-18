// https://atcoder.jp/contests/abc454/tasks/abc454_b

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
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi f(n);
    cin >> f;
    bool b1=1,b2=1;
    vi c(m,0);
    rep(i,n) {
        ++c[f[i]-1];
        if (c[f[i]-1]>1) b1=0;
    }
    rep(i,m) {
        if (c[i]==0) b2=0;
    }
    YesNo(b1);
    YesNo(b2);

    return 0;
}
