// https://atcoder.jp/contests/abc183/tasks/abc183_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using mint=modint1000000007;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    v<mint> r(h,0),c(w,0);
    map<int,mint> m;
    mint res;
    rep(i,h)rep(j,w) {
        res=(!i && !j);
        if (s[i][j]=='#') {
            r[i]=c[j]=m[i-j]=0;
        } else {
            res+=r[i]+c[j]+m[i-j];
            r[i]+=res;
            c[j]+=res;
            m[i-j]+=res;
        }
    }
    print(res.val());

    return 0;
}
