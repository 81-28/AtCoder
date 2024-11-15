// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_fh

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll w;
    cin >> w;
    ll mod = 1000000007;
    ll ans = 1;
    // ans *= 4;
    // ans *= 3;
    ans *= 12;
    // 上のマスが、前の列の下と一致する場合,しない場合
    // for (ll i=1; i<w; i++) ans = (ans*1*3+ans*2*2)%mod;
    // for (ll i=1; i<w; i++) ans = ans*7%mod;
    w--;
    ll seven = 7;
    for (; w>0; w/=2) {
        if (w%2) ans = ans*seven%mod;
        seven = seven*seven%mod;
    }
    print(ans);

    return 0;
}
