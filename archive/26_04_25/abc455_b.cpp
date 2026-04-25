// https://atcoder.jp/contests/abc455/tasks/abc455_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    int ans=0;
    rep(i,h)rep(j,w)for(int k=i; k<h; ++k)for(int l=j; l<w; ++l) {
        bool ok=1;
        for (int x=i; x<=k; ++x) {
            for (int y=j; y<=l; ++y) {
                if (s[x][y]!=s[i+k-x][j+l-y]) {
                    ok=0;
                    break;
                }
            }
            if (!ok) break;
        }
        ans+=ok;
    }
    print(ans);

    return 0;
}
