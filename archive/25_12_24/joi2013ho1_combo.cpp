// https://atcoder.jp/contests/joi2013ho/tasks/joi2013ho1

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    // idxとの偶奇の一致する/しないで分割
    vi c;
    int cmb=1;
    rep(i,n-1) {
        if (a[i]==a[i+1]) {
            c.pb(cmb);
            cmb=0;
        }
        ++cmb;
    }
    c.pb(cmb);
    // 連続する3区間の長さの最大値が答え
    int m=c.size();
    if (m<4) {
        print(n);
        return 0;
    }
    int ans=0;
    rep1(i,m-2) chmax(ans,c[i-1]+c[i]+c[i+1]);
    print(ans);

    return 0;
}
