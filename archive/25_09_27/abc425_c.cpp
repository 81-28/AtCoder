// https://atcoder.jp/contests/abc425/tasks/abc425_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    int idx=0;
    vi sm(n+1,0);
    rep1(i,n) sm[i]=sm[i-1]+a[i-1];
    while (q--) {
        int m;
        cin >> m;
        if (m==1) {
            int c;
            cin >> c;
            idx+=c;
            idx%=n;
        }
        if (m==2) {
            int l,r;
            cin >> l >> r;
            --l,--r;
            l+=idx,r+=idx;
            l%=n,r%=n;
            if (l<=r) print(sm[r+1]-sm[l]);
            else print(sm[n]-sm[l]+sm[r+1]);
        }
    }

    return 0;
}
