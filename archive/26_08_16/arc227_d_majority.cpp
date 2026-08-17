// https://atcoder.jp/contests/arc227/tasks/arc227_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
using vvb=v<vb>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,q;
    cin >> n >> m >> q;
    vector ok(m,v<vvb>(m,vvb(2,vb(2,0))));
    rep(i,n) {
        string s;
        cin >> s;
        rep(i,m)for(int j=i; j<m; ++j) {
            int a=s[i]&1;
            int b=s[j]&1;
            ok[i][j][a][b]=1;
        }
    }
    while (q--) {
        string s;
        cin >> s;
        bool ans=1;
        rep(i,m) {
            for(int j=i; j<m; ++j) {
                int a=s[i]&1;
                int b=s[j]&1;
                if (!ok[i][j][a][b]) {
                    ans=0;
                    break;
                }
            }
            if (!ans) break;
        }
        YesNo(ans);
    }

    return 0;
}
