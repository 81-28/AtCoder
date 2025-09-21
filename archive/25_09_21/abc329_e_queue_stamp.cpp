// https://atcoder.jp/contests/abc329/tasks/abc329_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    string s,t;
    cin >> n >> m >> s >> t;
    int ans=n;
    // スタンプの開始位置
    queue<int> q;
    rep(i,n+1-m) {
        bool ok=1;
        rep(j,m) {
            if (s[i+j]!=t[j]) {
                ok=0;
                break;
            }
        }
        if (ok) q.push(i);
    }
    while (!q.empty()) {
        int i=q.front();
        q.pop();
        int cnt=0;
        rep(j,m) {
            if (s[i+j]==t[j]) {
                ++cnt;
                s[i+j]='#';
            }
        }
        if (!cnt) continue;
        ans-=cnt;
        int b=max(i+1-m,0);
        int e=min(i+m,n+1-m);
        for (int j=b; j<e; ++j) {
            bool ok=1;
            cnt=m;
            rep(k,m) {
                if (s[j+k]=='#') --cnt;
                else if (s[j+k]!=t[k]) {
                    ok=0;
                    break;
                }
            }
            if (ok&&cnt) q.push(j);
        }
    }
    YesNo(!ans);

    return 0;
}
