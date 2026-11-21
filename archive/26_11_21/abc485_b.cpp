// https://atcoder.jp/contests/abc485/tasks/abc485_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<string> s(n);
    cin >> s;
    rep(i,n) {
        bool ok=1;
        rep(j,m) {
            if (s[i][j]=='o') {
                ok=0;
                break;
            }
        }
        if (ok) {
            print("Faucet",i+1);
            return 0;
        }
    }
    rep(j,m) {
        bool ok=1;
        rep(i,n) {
            if (s[i][j]=='o') {
                ok=0;
                break;
            }
        }
        if (ok) {
            print("Drain",j+1);
            return 0;
        }
    }

    return 0;
}
