// https://atcoder.jp/contests/abc430/tasks/abc430_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

void solve() {
    string a,b;
    cin >> a >> b;
    int n=b.size();
    auto z=z_algorithm(b+a+a);
    rep(i,n) {
        if (z[n+i]>=n) {
            print(i);
            return;
        }
    }
    print(-1);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
