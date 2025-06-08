// https://atcoder.jp/contests/abc300/tasks/abc300_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define YesNo(x) puts(x?"Yes":"No")
template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> a(h),b(h);
    cin >> a >> b;
    rep(s,h)rep(t,w) {
        bool ok=1;
        rep(i,h) {
            rep(j,w) {
                if (a[(s+i)%h][(t+j)%w]!=b[i][j]) {
                    ok=0;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}
