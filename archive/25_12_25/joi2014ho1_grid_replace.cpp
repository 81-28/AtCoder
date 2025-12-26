// https://atcoder.jp/contests/joi2014ho/tasks/joi2014ho1

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string joi="JOI";
    int m,n;
    cin >> m >> n;
    v<string> s(m);
    v<string> t(2);
    cin >> s >> t;
    int ans=0;
    vvi cnt(m,vi(n,0));
    rep(i,m-1)rep(j,n-1) {
        bool ok=1;
        rep(x,2) rep(y,2) {
            if (s[i+x][j+y]!=t[x][y]) ok=0;
        }
        if (ok) {
            ++ans;
            rep(x,2)rep(y,2) ++cnt[i+x][j+y];
        }
    }
    // 全ての位置で、全ての置換を試す
    int add=0;
    rep(i,m)rep(j,n) {
        rep(k,3) {
            int sm=0;
            if (s[i][j]==joi[k]) continue;
            if (i&&j && t[1][1]==joi[k]) {
                bool ok=1;
                rep(x,2)rep(y,2) {
                    if (!(x==1&&y==1) && s[i-1+x][j-1+y]!=t[x][y]) ok=0;
                }
                if (ok) ++sm;
            }
            if (i&&j+1<n && t[1][0]==joi[k]) {
                bool ok=1;
                rep(x,2)rep(y,2) {
                    if (!(x==1&&y==0) && s[i-1+x][j+y]!=t[x][y]) ok=0;
                }
                if (ok) ++sm;
            }
            if (i+1<m&&j && t[0][1]==joi[k]) {
                bool ok=1;
                rep(x,2)rep(y,2) {
                    if (!(x==0&&y==1) && s[i+x][j-1+y]!=t[x][y]) ok=0;
                }
                if (ok) ++sm;
            }
            if (i+1<m&&j+1<n && t[0][0]==joi[k]) {
                bool ok=1;
                rep(x,2)rep(y,2) {
                    if (!(x==0&&y==0) && s[i+x][j+y]!=t[x][y]) ok=0;
                }
                if (ok) ++sm;
            }
            chmax(add,sm-cnt[i][j]);
        }
    }
    print(ans+add);

    return 0;
}
