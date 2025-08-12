// https://atcoder.jp/contests/abc337/tasks/abc337_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,k;
    cin >> h >> w >> k;
    v<string> s(h);
    cin >> s;
    int ans=k+1;
    rep(i,h) {
        vi x(w+1,0),d=x;
        rep(j,w) {
            x[j+1]=x[j]+(s[i][j]=='x');
            d[j+1]=d[j]+(s[i][j]=='.');
        }
        for (int j=0; j+k<=w; ++j) {
            if (x[j+k]-x[j]==0) chmin(ans,d[j+k]-d[j]);
        }
    }
    rep(j,w) {
        vi x(h+1,0),d=x;
        rep(i,h) {
            x[i+1]=x[i]+(s[i][j]=='x');
            d[i+1]=d[i]+(s[i][j]=='.');
        }
        for (int i=0; i+k<=h; ++i) {
            if (x[i+k]-x[i]==0) chmin(ans,d[i+k]-d[i]);
        }
    }
    print(ans==k+1?-1:ans);

    return 0;
}
