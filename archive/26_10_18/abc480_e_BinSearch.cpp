// https://atcoder.jp/contests/abc480/tasks/abc480_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int n;
// 長さl、初項a、公差d、の等差数列の積がn以下であるか
bool ok(int l,int a,int d) {
    int m=n;
    while (l--) {
        m/=a;
        if (!m) return 0;
        a+=d;
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    // 19! = 1.2e17 = 121645100408832000
    // 20! = 2.4e18 = 2432902008176640000
    // |A|<20

    // |A|>=3
    // Π <= 1e18
    // A1 < 1e6

    cin >> n;
    int ans=0;
    // 長さ
    for (int i=3; ok(i,1,1); ++i) {
        // 初項
        for (int j=1; ok(i,j,1); ++j) {
            // 公差 [l,r)
            int l=1,r=1e9;
            while (l+1<r) {
                int m=(l+r)/2;
                if (ok(i,j,m)) l=m;
                else r=m;
            }
            ans+=l;
        }
    }
    print(ans);

    return 0;
}
