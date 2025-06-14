// https://atcoder.jp/contests/abc410/tasks/abc410_b

#include<bits/stdc++.h>
using namespace std;
#define int ll

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<class T> constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
using ll=long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi b(q),c(n,0);
    int mi=0;
    rep(i,q) {
        int x;
        cin >> x;
        int pos=x?x-1:mi;
        b[i]=pos+1;
        ++c[pos];
        int m=q;
        rep(j,n) {
            if (chmin(m,c[j])) mi=j;
        }
    }
    print(b);

    return 0;
}
