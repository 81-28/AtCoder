// https://atcoder.jp/contests/abc301/tasks/abc301_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define YesNo(x) puts(x?"Yes":"No")
#define f first
#define s second
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string st,t;
    cin >> st >> t;
    int n=t.size();
    vvi c(2,vi(26,0));
    pii a={0,0};
    rep(i,n) {
        if (st[i]=='@') ++a.f;
        else ++c[0][st[i]-'a'];
        if (t[i]=='@') ++a.s;
        else ++c[1][t[i]-'a'];
    }
    string atc="atcoder";
    pii d{0,0};
    rep(i,26) {
        if (c[0][i]==c[1][i]) continue;
        if (atc.find(char('a'+i))==-1) {
            YesNo(0);
            return 0;
        }
        if (c[0][i]>c[1][i]) d.f+=(c[0][i]-c[1][i]);
        else d.s+=(c[1][i]-c[0][i]);
    }
    YesNo(a.f>=d.s&&a.s>=d.f);

    return 0;
}
