// https://atcoder.jp/contests/abc343/tasks/abc343_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

bool isPal(const ll& n) {
    string s = to_string(n);
    int len = s.size();
    int l = 0,r = len-1;
    while (l<r) {
        if (s[l]!=s[r]) return 0;
        l++,r--;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    ll ans=1;
    for (ll i=1; i*i*i<=n; i++) {
        if (isPal(i*i*i)) ans = i*i*i;
    }
    print(ans);

    return 0;
}
