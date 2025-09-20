// https://atcoder.jp/contests/abc331/tasks/abc331_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<string> p(n);
    cin >> p;
    vvi s(n,vi(n,0));
    rep(i,n)rep(j,n) {
        if (p[i][j]=='B') ++s[i][j];
        if (i) s[i][j]+=s[i-1][j];
        if (j) s[i][j]+=s[i][j-1];
        if (i&&j) s[i][j]-=s[i-1][j-1];
    }
    while (q--) {
        vi a(4);
        cin >> a;
        int ul=0,ur=0,dl=0,dr=0;
        if (a[0]&&a[1]) {
            ul+=s[n-1][n-1]*((a[0]-1)/n)*((a[1]-1)/n);
            ul+=s[(a[0]-1)%n][n-1]*((a[1]-1)/n);
            ul+=s[n-1][(a[1]-1)%n]*((a[0]-1)/n);
            ul+=s[(a[0]-1)%n][(a[1]-1)%n];
        }
        if (a[0]) {
            ur+=s[n-1][n-1]*((a[0]-1)/n)*(a[3]/n);
            ur+=s[(a[0]-1)%n][n-1]*(a[3]/n);
            ur+=s[n-1][a[3]%n]*((a[0]-1)/n);
            ur+=s[(a[0]-1)%n][a[3]%n];
        }
        if (a[1]) {
            dl+=s[n-1][n-1]*(a[2]/n)*((a[1]-1)/n);
            dl+=s[a[2]%n][n-1]*((a[1]-1)/n);
            dl+=s[n-1][(a[1]-1)%n]*(a[2]/n);
            dl+=s[a[2]%n][(a[1]-1)%n];
        }
        dr+=s[n-1][n-1]*(a[2]/n)*(a[3]/n);
        dr+=s[a[2]%n][n-1]*(a[3]/n);
        dr+=s[n-1][a[3]%n]*(a[2]/n);
        dr+=s[a[2]%n][a[3]%n];
        print(ul-ur-dl+dr);
    }

    return 0;
}
