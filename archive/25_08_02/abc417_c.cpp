// https://atcoder.jp/contests/abc417/tasks/abc417_c

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

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    rep(i,n) a[i]+=n-1-i;
    map<int,int> m;
    rep(i,n) ++m[a[i]];
    int ans=0;
    rep(i,n-1) {
        --m[a[i]];
        ans+=m[(n-1-i)*2-a[i]];
    }
    print(ans);

    return 0;
}
