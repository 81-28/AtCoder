// https://atcoder.jp/contests/abc159/tasks/abc159_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,k;
    cin >> h >> w >> k;
    v<string> s(h);
    cin >> s;
    vvi sm(h+1,vi(w+1,0));
    rep1(i,h)rep1(j,w) sm[i][j]=(s[i-1][j-1]-'0')+sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1];
    int mx=1<<(h-1);
    int ans=h*w;
    rep(m,mx) {
        int res=0,l=0;
        vb b(h+1,0);
        rep(i,h-1) res+=!(b[i+1]=(m>>i)&1);
        bool ok=1;
        rep1(j,w) {
            int lsm=0;
            rep1(i,h) {
                if (b[i]) continue;
                int nsm=sm[i][j]-sm[i][l];
                if (nsm-lsm>k) {
                    if (j-l<2) ok=0;
                    ++res;
                    l=--j;
                    break;
                }
                lsm=nsm;
            }
            if (!ok) break;
        }
        if (ok) chmin(ans,res);
    }
    print(ans);

    return 0;
}
