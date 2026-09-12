// https://atcoder.jp/contests/abc475/tasks/abc475_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m=1e3;
    cin >> n;
    vi a(n),ans(3,0);
    cin >> a;
    rep(i,n) {
        int r=(a[i]+m-1)/m;
        int d=r*m-a[i];
        rep(j,3) {
            ans[j]+=d%10;
            d/=10;
        }
    }
    print(ans);

    return 0;
}
