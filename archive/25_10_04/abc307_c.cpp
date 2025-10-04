// https://atcoder.jp/contests/abc307/tasks/abc307_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    v<pii> p(3);
    v<v<string>> a(3);
    v<v<v<bool>>> b(3);
    int cnt=0;
    rep(i,3) {
        cin >> p[i];
        a[i]=v<string>(p[i].f);
        cin >> a[i];
        b[i]=v<v<bool>>(p[i].f,v<bool>(p[i].s,0));
        rep(j,p[i].f)rep(k,p[i].s) {
            b[i][j][k]=(a[i][j][k]=='#');
            if (i<2) cnt+=b[i][j][k];
        }
    }
    for (int x0=-p[0].f+1; x0<p[2].f; ++x0) {
        for (int y0=-p[0].s+1; y0<p[2].s; ++y0) {
            for (int x1=-p[1].f+1; x1<p[2].f; ++x1) {
                for (int y1=-p[1].s+1; y1<p[2].s; ++y1) {
                    bool ok=1;
                    int c=0;
                    rep(i,p[2].f) {
                        rep(j,p[2].s) {
                            bool b0=0,b1=0;
                            int i0=i-x0,j0=j-y0,i1=i-x1,j1=j-y1;
                            if (0<=i0&&i0<p[0].f && 0<=j0&&j0<p[0].s) b0=b[0][i0][j0];
                            if (0<=i1&&i1<p[1].f && 0<=j1&&j1<p[1].s) b1=b[1][i1][j1];
                            c+=b0+b1;
                            if ((b0|b1)!=b[2][i][j]) {
                                ok=0;
                                break;
                            }
                        }
                        if (!ok) break;
                    }
                    if (c==cnt && ok) {
                        YesNo(1);
                        return 0;
                    }
                }
            }
        }
    }
    YesNo(0);

    return 0;
}
