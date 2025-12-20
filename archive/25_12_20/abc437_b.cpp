// https://atcoder.jp/contests/abc437/tasks/abc437_b

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

    int h,w,n;
    cin >> h >> w >> n;
    vvi a(h,vi(w));
    cin >> a;
    map<int,int> m;
    rep(i,n) {
        int b;
        cin >> b;
        ++m[b];
    }
    int ans=0;
    rep(i,h) {
        int res=0;
        rep(j,w) res+=m[a[i][j]];
        chmax(ans,res);
    }
    print(ans);

    return 0;
}
