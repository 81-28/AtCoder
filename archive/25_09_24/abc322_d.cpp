// https://atcoder.jp/contests/abc322/tasks/abc322_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


// ポリオミノをn*90°回転
v<v<bool>> rotate(const v<string>& st,const int& n) {
    int h=st.size(),w=st[0].size();
    if (n%2==0) {
        v<v<bool>> r(h,v<bool>(w,0));
        if (!n) {
            rep(i,h)rep(j,w) {
                if (st[i][j]=='#') r[i][j]=1;
            }
        } else {
            rep(i,h)rep(j,w) {
                if (st[h-1-i][w-1-j]=='#') r[i][j]=1;
            }
        }
        return r;
    } else {
        v<v<bool>> r(w,v<bool>(h,0));
        if (n==1) {
            rep(i,w)rep(j,h) {
                if (st[h-1-j][i]=='#') r[i][j]=1;
            }
        } else {
            rep(i,w)rep(j,h) {
                if (st[j][w-1-i]=='#') r[i][j]=1;
            }
        }
        return r;
    }
}

// ポリオミノbをpだけずらしておけるかどうか
bool check(const v<v<v<bool>>>& b,const v<pii>& p) {
    v<v<bool>> r(4,v<bool>(4,0));
    rep(i,3) {
        int h=b[i].size(),w=b[i][0].size();
        rep(j,h)rep(k,w) {
            if (!b[i][j][k]) continue;
            if (r[p[i].f+j][p[i].s+k]) return 0;
            r[p[i].f+j][p[i].s+k]=1;
        }
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    v<v<string>> p(3,v<string>(4));
    cin >> p;
    v<pii> siz(3,{0,0});
    int cnt=0;
    rep(i,3) {
        int be=-1,en=-1;
        rep(j,4) {
            bool ok=0;
            rep(k,4) {
                if (p[i][j][k]=='#') {
                    ok=1;
                    ++cnt;
                }
            }
            if (ok) {
                ++siz[i].f;
                if (be==-1) be=j;
                en=j;
            }
        }
        v<string> pp;
        for (int j=be; j<=en; ++j) {
            pp.pb(p[i][j]);
        }
        p[i]=pp;
        be=-1,en=-1;
        rep(k,4) {
            bool ok=0;
            rep(j,siz[i].f) {
                if (p[i][j][k]=='#') {
                    ok=1;
                    break;
                }
            }
            if (ok) {
                ++siz[i].s;
                if (be==-1) be=k;
                en=k;
            }
        }
        pp=v<string>(siz[i].f,"");
        for (int k=be; k<=en; ++k) {
            rep(j,siz[i].f) pp[j]+=p[i][j][k];
        }
        p[i]=pp;
    }
    if (cnt!=16) {
        YesNo(0);
        return 0;
    }
    // b[i][j]:i個目をj*90°回転させたもの
    v<v<v<v<bool>>>> b(3,v<v<v<bool>>>(4));
    rep(i,3)rep(j,4) b[i][j]=rotate(p[i],j);
    int r0=0;
    int h0=b[0][r0].size(),w0=b[0][r0][0].size();
    rep(r1,4) {
        int h1=b[1][r1].size(),w1=b[1][r1][0].size();
        rep(r2,4) {
            int h2=b[2][r2].size(),w2=b[2][r2][0].size();
            rep(x0,5-h0)rep(y0,5-w0)rep(x1,5-h1)rep(y1,5-w1)rep(x2,5-h2)rep(y2,5-w2) {
                if (check({b[0][r0],b[1][r1],b[2][r2]},{{x0,y0},{x1,y1},{x2,y2}})) {
                    YesNo(1);
                    return 0;
                }
            }
        }
    }
    YesNo(0);

    return 0;
}
