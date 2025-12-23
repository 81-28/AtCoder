// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e

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

    int r,c;
    cin >> r >> c;
    vvi a(r,vi(c));
    cin >> a;
    int ans=0;
    int mx=1LL<<r;
    // i[j]:行jを裏返すかどうか
    rep(i,mx) {
        int res=0;
        rep(j,c) {
            int sm=0;
            rep(k,r) {
                if (((i>>k)&1)==a[k][j]) ++sm;
            }
            res+=max(sm,r-sm);
        }
        chmax(ans,res);
    }
    print(ans);

    return 0;
}
