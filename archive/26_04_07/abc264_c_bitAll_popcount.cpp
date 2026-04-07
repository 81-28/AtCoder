// https://atcoder.jp/contests/abc264/tasks/abc264_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    vvi a(h,vi(w));
    cin >> a;
    int hh,ww;
    cin >> hh >> ww;
    vvi b(hh,vi(ww));
    cin >> b;
    int mxh=1<<h,mxw=1<<w;
    rep(i,mxh) {
        int cnt=0;
        for (int k=i; k; k/=2) cnt+=k&1;
        if (cnt!=hh) continue;
        rep(j,mxw) {
            cnt=0;
            for (int k=j; k; k/=2) cnt+=k&1;
            if (cnt!=ww) continue;
            bool ok=1;
            int xx=0;
            rep(x,h) {
                if (!((i>>x)&1)) continue;
                int yy=0;
                rep(y,w) {
                    if (!((j>>y)&1)) continue;
                    if (a[x][y]!=b[xx][yy++]) {
                        ok=0;
                        break;
                    }
                }
                if (!ok) break;
                ++xx;
            }
            if (ok) {
                YesNo(1);
                return 0;
            }
        }
    }
    YesNo(0);

    return 0;
}
