// https://atcoder.jp/contests/abc457/tasks/abc457_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi l(n);
    vvi a(n);
    rep(i,n) {
        cin >> l[i];
        a[i]=vi(l[i]);
        cin >> a[i];
    }
    vi c(n);
    cin >> c;
    rep(i,n) {
        int len=l[i]*c[i];
        if (len<k) {
            k-=len;
            continue;
        }
        print(a[i][(k-1)%l[i]]);
        break;
    }

    return 0;
}
