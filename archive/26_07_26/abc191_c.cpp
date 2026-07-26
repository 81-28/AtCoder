// https://atcoder.jp/contests/abc191/tasks/abc191_c

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
    cout<<fixed<<setprecision(16);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    int ans=0;
    rep(i,h-1)rep(j,w-1) {
        int cnt=0;
        if (s[i][j]=='#') ++cnt;
        if (s[i][j+1]=='#') ++cnt;
        if (s[i+1][j]=='#') ++cnt;
        if (s[i+1][j+1]=='#') ++cnt;
        if (cnt&1) ++ans;
    }
    print(ans);

    return 0;
}
