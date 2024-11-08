// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_fb

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
    set<ll> ans;
    for (ll i=1;i*i<=n;i++) {
        if (n%i) continue;
        ans.insert(i);
        ans.insert(n/i);
    }
    for(ll val:ans) print(val);

    return 0;
}
