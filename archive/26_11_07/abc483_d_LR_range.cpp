// https://atcoder.jp/contests/abc483/tasks/abc483_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    // 右から反転させなかった場合の移動できる範囲
    // {現在地,最小,最大}
    v<tuple<int,int,int>> r(n+1);
    r[n]={0,0,0};
    for (int i=n-1; i>=0; --i) {
        auto&[pos,mi,mx]=r[i]=r[i+1];
        pos+=a[i];
        chmin(mi,pos),chmax(mx,pos);
    }

    auto[pos,mi,mx]=r[0];
    int ans=mx-mi;
    // 左端から反転させなかった場合も同様に考える
    pos=mi=mx=0;
    // i番目を反転させる場合
    rep(i,n) {
        auto[pr,mir,mxr]=r[i+1];
        pos-=a[i];
        chmax(ans,max(mx,pos+(pr-mir))-min(mi,pos-(mxr-pr)));

        pos+=a[i]*2;
        chmin(mi,pos),chmax(mx,pos);
    }
    print(ans+1);

    return 0;
}
