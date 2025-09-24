// https://atcoder.jp/contests/abc349/tasks/abc349_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


const int inf=LLONG_MAX;
const pii pinf[2]={{inf,0},{0,inf}};

// 勝敗判定
bool check(const vvi& b,const bool& t) {
    int c=1+t;
    bool ok;
    rep(i,3) {
        ok=1;
        rep(j,3) {
            if (b[i][j]!=c) {
                ok=0;
                break;
            }
        }
        if (ok) return 1;
    }
    rep(j,3) {
        ok=1;
        rep(i,3) {
            if (b[i][j]!=c) {
                ok=0;
                break;
            }
        }
        if (ok) return 1;
    }
    ok=1;
    rep(i,3) {
        if (b[i][i]!=c) {
            ok=0;
            break;
        }
    }
    if (ok) return 1;
    ok=1;
    rep(i,3) {
        if (b[i][2-i]!=c) {
            ok=0;
            break;
        }
    }
    return ok;
}

vvi a(3,vi(3));
// 最適な(相手に得点を取らせない)行動をする
// {高橋,青木}の得点
// (ボード状況,ターン)
// 0:無し,1:高橋,2:青木
pii dfs(const vvi& b,const bool& t,const int& cnt) {
    pii res=!t?pii(-inf,inf):pii(inf,-inf);
    rep(i,3)rep(j,3) {
        if (!b[i][j]) {
            vvi nb=b;
            nb[i][j]=1+t;
            if (check(nb,t)) {
                return !t?pinf[0]:pinf[1];
            } else {
                pii nxt;
                if (cnt==8) {
                    int score[2]={0,0};
                    rep(x,3)rep(y,3) score[nb[x][y]-1]+=a[x][y];
                    nxt={score[0],score[1]};
                } else {
                    nxt=dfs(nb,!t,cnt+1);
                }
                if (!t) {
                    if (res.s>nxt.s) res=nxt;
                } else {
                    if (res.f>nxt.f) res=nxt;
                }
            }
        }
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> a;
    pii p=dfs(vvi(3,vi(3,0)),0,0);
    print(p.f>p.s?"Takahashi":"Aoki");

    return 0;
}
