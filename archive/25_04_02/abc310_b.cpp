// https://atcoder.jp/contests/abc310/tasks/abc310_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) puts(x?"Yes":"No")
template<typename T>
using v=vector<T>;
using vi=v<int>;


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi p(n);
    int c;
    v<unordered_set<int>> f(n);
    int a;
    rep(i,n) {
        cin >> p[i] >> c;
        rep(j,c) {
            cin >> a;
            f[i].insert(a);
        }
    }
    bool b;
    rep(i,n) {
        rep(j,n) {
            if (i==j) continue;
            if (p[i]<p[j]) continue;
            b=1;
            for (int val:f[i]) {
                if (f[j].find(val)==f[j].end()) {
                    b=0;
                    break;
                }
            }
            if (!b) continue;
            if (p[i]==p[j] && f[j].size()<=f[i].size()) continue;
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}
