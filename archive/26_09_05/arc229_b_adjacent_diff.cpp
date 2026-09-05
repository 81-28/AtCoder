// https://atcoder.jp/contests/arc229/tasks/arc229_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


void solve() {
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    if (!sum(a)) {
        print(0);
        return;
    }
    int ans=1;
    int sm=0;
    rep(i,n-1) {
        int d=a[i]-2*a[i+1];
        if (d<0) {
            print(-1);
            return;
        }
        chmax(ans,d);
        sm+=d;
    }
    sm+=a[n-1];
    if (ans>sm) {
        print(-1);
        return;
    }
    print(ans);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
