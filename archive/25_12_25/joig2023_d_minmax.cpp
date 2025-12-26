// https://atcoder.jp/contests/joig2023-open/tasks/joig2023_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

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
    vi r(h,0),c(w,0);
    int cnt=0;
    rep(i,h)rep(j,w) {
        if (s[i][j]=='#') ++r[i],++c[j],++cnt;
    }
    // 最小値最大化
    int mx=0;
    rep(i,h) {
        int mi=h*w;
        rep(j,w) {
            if (s[i][j]=='#') chmin(mi,cnt-(r[i]-1)+(w-r[i])-(c[j]-1)+(h-c[j]));
            else chmin(mi,cnt-r[i]+(w-r[i]-1)-c[j]+(h-c[j]-1));
        }
        chmax(mx,mi);
    }
    print(mx,h*w-mx);

    return 0;
}
