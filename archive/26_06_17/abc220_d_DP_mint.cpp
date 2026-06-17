// https://atcoder.jp/contests/abc220/tasks/abc220_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using mint=modint998244353;
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
    // ans[i][j]:i回の操作後、左端の数がjであるパターン数
    vector ans(n,v<mint>(10,0));
    ans[0][a[0]]=1;
    rep(i,n-1) {
        rep(j,10) {
            ans[i+1][(j+a[i+1])%10]+=ans[i][j];
            ans[i+1][(j*a[i+1])%10]+=ans[i][j];
        }
    }
    rep(i,10) print(ans[n-1][i].val());

    return 0;
}
