// https://atcoder.jp/contests/abc473/tasks/abc473_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    vi cnt(k,0);
    rep(i,n) ++cnt[--a[i]];
    sort(all(cnt));
    int ans=0;
    rep(i,k) {
        if (cnt[i]+1<cnt.back()) continue;
        ++ans;
    }
    print(ans);

    return 0;
}
