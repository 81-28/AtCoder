// https://atcoder.jp/contests/abc422/tasks/abc422_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
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
    v<string> s(h);
    cin >> s;
    bool ok=1;
    rep(i,h)rep(j,w) {
        if (s[i][j]=='.') continue;
        int cnt=0;
        if (i && s[i-1][j]=='#') ++cnt;
        if (j && s[i][j-1]=='#') ++cnt;
        if (i+1<h && s[i+1][j]=='#') ++cnt;
        if (j+1<w && s[i][j+1]=='#') ++cnt;
        if (cnt!=2 && cnt!=4) {
            ok=0;
            break;
        }
    }
    YesNo(ok);

    return 0;
}
