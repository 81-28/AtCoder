// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dj
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    ll ans=0,i=0,ten=1;
    int d;
    for(ll m=n; m>0; m/=10){
        // 現在の位の数
        d = m%10;
        if (m!=n){
            // 現在の位より小さい位の数の和
            ans += d*i*45*ten;
            ten*=10;
        }
        // 現在の位の今までの和
        ans += (d-1)*d*ten/2;
        // 現在の位の数*登場した回数
        ans += d*(n%ten + 1);
        i++;
    }
    cout<<ans<<'\n';

    return 0;
}
