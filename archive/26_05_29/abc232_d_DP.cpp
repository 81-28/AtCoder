// https://atcoder.jp/contests/abc232/tasks/abc232_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    vvi a(h,vi(w,0));
    a[0][0]=1;
    int ans=0;
    rep(i,h)rep(j,w) {
        if (s[i][j]=='#') continue;
        if (i&&a[i-1][j]) chmax(a[i][j],a[i-1][j]+1);
        if (j&&a[i][j-1]) chmax(a[i][j],a[i][j-1]+1);
        chmax(ans,a[i][j]);
    }
    print(ans);

    return 0;
}
