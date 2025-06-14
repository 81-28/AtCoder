// https://atcoder.jp/contests/abc410/tasks/abc410_c

#include<bits/stdc++.h>
using namespace std;
#define int ll

#define rep(i,n) for(int i=0;i<(int)(n);++i)
using ll=long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n);
    rep(i,n) a[i]=i+1;
    int d=0;
    while (q--) {
        int m;
        cin >> m;
        if (m==1) {
            int p,x;
            cin >> p >> x;
            a[(p-1+d)%n]=x;
        }
        if (m==2) {
            int p;
            cin >> p;
            print(a[(p-1+d)%n]);
        }
        if (m==3) {
            int k;
            cin >> k;
            d+=k,d%=n;
        }
    }

    return 0;
}
