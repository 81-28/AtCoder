// https://atcoder.jp/contests/abc457/tasks/abc457_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    // k回以下の操作で実現可能である最小値の範囲
    // [l,r)
    int l=0,r=INF;
    while (l+1<r) {
        int m=(l+r)/2;
        int cnt=0;
        bool ok=1;
        rep(i,n) {
            int d=m-a[i];
            if (d<1) continue;
            cnt+=(d-1)/(i+1)+1;
            if (cnt>k) {
                ok=0;
                break;
            }
        }
        if (ok) l=m;
        else r=m;
    }
    print(l);

    return 0;
}
