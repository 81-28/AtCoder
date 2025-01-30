// https://atcoder.jp/contests/abc327/tasks/abc327_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(m),b(m);
    cin >> a >> b;
    vi x(n+1,-1);
    vi p(n+1);
    rep1(i,n) p[i]=i;

    int q;
    rep(i,m) {
        if (a[i]==b[i]) {
            YesNo(0);
            return 0;
        }
        if (x[a[i]]==-1) {
            if (x[b[i]]==-1) {
                x[a[i]] = 0;
                x[b[i]] = 1;
                p[b[i]] = a[i];
            } else {
                x[a[i]] = 1 - x[b[i]];
                p[a[i]] = p[b[i]];
            }
        } else {
            if (x[b[i]]==-1) {
                x[b[i]] = 1 - x[a[i]];
                p[b[i]] = p[a[i]];
            } else {
                if (p[a[i]] == p[b[i]]) {
                    if (x[a[i]] == x[b[i]]) {
                        YesNo(0);
                        return 0;
                    }
                } else {
                    q=p[b[i]];
                    if (x[a[i]] == x[b[i]]) {
                        rep1(j,n) {
                            if (p[j]==q) x[j]^=1;
                        }
                    }
                    rep1(j,n) {
                        if (p[j]==q) p[j]=p[a[i]];
                    }
                }
            }
        }
    }
    YesNo(1);

    return 0;
}
