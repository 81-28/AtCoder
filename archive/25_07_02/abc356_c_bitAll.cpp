// https://atcoder.jp/contests/abc356/tasks/abc356_c

#include<bits/stdc++.h>
using namespace std;

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

    int n,m,k;
    cin >> n >> m >> k;
    vvi a(m);
    v<char> r(m);
    rep(i,m) {
        int c;
        cin >> c;
        a[i]=vi(c);
        cin >> a[i] >> r[i];
    }
    int mx=pow(2,n);
    int ans=0;
    rep(i,mx) {
        bool ok=1;
        rep(j,m) {
            int sm=0;
            for (auto val:a[j]) {
                sm+=(i>>(val-1))%2;
            }
            if (!(sm>=k && r[j]=='o') && !(sm<k && r[j]=='x')) {
                ok=0;
                break;
            }
        }
        ans+=ok;
    }
    print(ans);

    return 0;
}
