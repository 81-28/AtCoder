// https://atcoder.jp/contests/abc480/tasks/abc480_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k,t;
    cin >> n >> k >> t;
    vi a(n);
    cin >> a;
    a.pb(-k),a.pb(t);
    sort(all(a));
    int ans=0;
    rep(i,n+1) {
        ans+=max(0,a[i+1]-a[i]-1)/k;
        if (a[i+1]>=t) break;
    }
    print(ans);

    return 0;
}
