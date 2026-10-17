// https://atcoder.jp/contests/abc480/tasks/abc480_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    v<string> t(2);
    cin >> t;
    pii a,d;
    rep(i,2)rep(j,2) {
        if (t[i][j]=='A') a={i,j};
        if (t[i][j]=='D') d={i,j};
    }
    YesNo(a.f==d.f || a.s==d.s);

    return 0;
}
