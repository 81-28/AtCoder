// https://storage.googleapis.com/files.icpc.jp/domestic2025/problems/problems_ja.pdf

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<class T>constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int solve(const int& n,const int& m) {
    v<string> s(n);
    cin >> s;
    vvi a(n);
    bool ok=1;
    int cmb=1;
    rep(i,n) {
        cmb=1;
        for (int j=1; j<m; ++j) {
            if (s[i][j-1]!=s[i][j]) {
                a[i].pb(cmb);
                cmb=1;
            } else ++cmb;
        }
        a[i].pb(cmb);
        if (i) {
            for (int j=0; j<(int)a[0].size(); ++j) {
                if (a[i][j]!=a[0][j]) {
                    ok=0;
                    break;
                }
            }
            if (!ok) break;
        }
    }
    if (!ok) return -1;
    cmb=1;
    vi b;
    for (int i=1; i<n; ++i) {
        if (s[i-1][0]!=s[i][0]) {
            b.pb(cmb);
            cmb=1;
        } else ++cmb;
    }
    b.pb(cmb);
    int an=a[0].size();
    int bn=b.size();
    for (int i=2; i+1<an; ++i) {
        if (a[0][i]!=a[0][1]) {
            ok=0;
            break;
        }
    }
    if (!ok) return -1;
    chmin(an,3);
    for (int i=2; i+1<bn; ++i) {
        if (b[i]!=b[1]) {
            ok=0;
            break;
        }
    }
    if (!ok) return -1;
    chmin(bn,3);
    if (an==3) {
        if (bn==3) {
            if (a[0][1]==b[1]) {
                if (*a[0].begin()>a[0][1] || *a[0].rbegin()>a[0][1]) {
                    ok=0;
                }
                if (*b.begin()>b[1] || *b.rbegin()>b[1]) {
                    ok=0;
                }
                if (ok) return b[1];
                else return -1;
            } else return -1;
        } else {
            if (*a[0].begin()>a[0][1] || *a[0].rbegin()>a[0][1]) {
                ok=0;
            }
            if (!ok) return -1;
            for (int val:b) {
                if (val>a[0][1]) {
                    ok=0;
                    break;
                }
            }
            if (ok) return a[0][1];
            else return -1;
        }
    } else {
        if (bn==3) {
            if (*b.begin()>b[1] || *b.rbegin()>b[1]) {
                ok=0;
            }
            if (!ok) return -1;
            for (int val:a[0]) {
                if (val>b[1]) {
                    ok=0;
                    break;
                }
            }
            if (ok) return b[1];
            else return -1;
        } else return 0;
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    while (1) {
        int n,m;
        cin >> n >> m;
        if (n==0) return 0;
        print(solve(n,m));
    }

    return 0;
}
