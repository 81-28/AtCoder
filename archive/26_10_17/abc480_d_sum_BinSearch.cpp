// https://atcoder.jp/contests/abc480/tasks/abc480_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int n;
vi a,sm;
int s(int x) {
    int l=0,r=n;
    while (l+1<r) {
        int m=(l+r)/2;
        if (m*(m+1)/2 >x) r=m;
        else l=m;
    }
    x-=l*(l+1)/2;
    // 綺麗に階段をなす部分と、余り
    return sm[l]+a[x];
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    cin >> n >> q;
    // 累積和
    a=vi(n+1,0);
    rep1(i,n) {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    // 累積和の累積和
    sm=a;
    rep1(i,n) sm[i]+=sm[i-1];
    while (q--) {
        int l,r;
        cin >> l >> r;
        print(s(r)-s(--l));
    }

    return 0;
}
