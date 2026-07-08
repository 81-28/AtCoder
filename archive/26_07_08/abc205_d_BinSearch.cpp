// https://atcoder.jp/contests/abc205/tasks/abc205_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    while (q--) {
        int k;
        cin >> k;
        // (l,r]
        // cnt[0]=0,cnt[INF]>k;
        int l=0,r=INF;
        while (l+1<r) {
            int m=(l+r)/2;
            auto it=upper_bound(all(a),m);
            // m以下の良い整数の個数
            int cnt=m-(it-a.begin());
            if (cnt>=k) r=m;
            else l=m;
        }
        print(r);
    }

    return 0;
}
