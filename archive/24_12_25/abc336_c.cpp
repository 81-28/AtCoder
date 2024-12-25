// https://atcoder.jp/contests/abc336/tasks/abc336_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    n--;
    ll ans = 0;
    ll d = 1;
    for (; n > 0; n/=5) {
        ans += n%5*2*d;
        d*=10;
    }
    print(ans);

    return 0;
}
