// https://atcoder.jp/contests/abc289/tasks/abc289_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi a(m);
    rep(i,m) {
        int c;
        cin >> c;
        a[i]=vi(c);
        cin >> a[i];
    }
    int mx=1<<m;
    int ans=0;
    rep(i,mx) {
        v<bool> b(n+1,0);
        rep(j,m) {
            if ((i>>j)&1) continue;
            for (int val:a[j]) b[val]=1;
        }
        bool ok=1;
        rep1(j,n) {
            if (!b[j]) {
                ok=0;
                break;
            }
        }
        ans+=ok;
    }
    print(ans);

    return 0;
}
