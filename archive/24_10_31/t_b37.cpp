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
        d = m%10;
        if (m!=n){
            ans += d*i*45*ten;
            ten*=10;
        }
        ans += (d-1)*d*ten/2;
        ans += d*(n%ten + 1);
        i++;
    }
    cout<<ans<<'\n';

    return 0;
}
