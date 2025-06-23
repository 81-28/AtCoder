// https://atcoder.jp/contests/abc297/tasks/abc297_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define YesNo(x) puts(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    vi b(2,-1),r=b;
    int k=-1;
    rep(i,8) {
        if (s[i]=='B') {
            if (b[0]==-1) b[0]=i;
            else b[1]=i;
        }
        if (s[i]=='R') {
            if (r[0]==-1) r[0]=i;
            else r[1]=i;
        }
        if (s[i]=='K') k=i;
    }
    YesNo(b[0]%2!=b[1]%2 && r[0]<k && k<r[1]);

    return 0;
}
