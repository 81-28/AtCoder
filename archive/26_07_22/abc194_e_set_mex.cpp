// https://atcoder.jp/contests/abc194/tasks/abc194_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    set<int> s;
    rep(i,n+1) s.insert(i);
    vi cnt(n,0);
    rep(i,m-1) {
        if (!cnt[a[i]]++) s.erase(a[i]);
    }
    int ans=n+1;
    rep(i,n-m+1) {
        if (!cnt[a[m-1+i]]++) s.erase(a[m-1+i]);
        chmin(ans,*s.begin());
        if (!--cnt[a[i]]) s.insert(a[i]);
    }
    print(ans);

    return 0;
}
