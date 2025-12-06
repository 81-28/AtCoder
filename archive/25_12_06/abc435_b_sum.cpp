// https://atcoder.jp/contests/abc435/tasks/abc435_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

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
    // sm[i+1]:a[i]までの累積和
    vi sm(n+1,0);
    rep1(i,n) sm[i]=sm[i-1]+a[i-1];
    int ans=0;
    rep(l,n)for(int r=l; r<n; ++r) {
        bool ok=1;
        for (int i=l; i<=r; ++i) {
            if ((sm[r+1]-sm[l])%a[i]==0) {
                ok=0;
                break;
            }
        }
        ans+=ok;
    }
    print(ans);

    return 0;
}
