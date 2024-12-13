// https://atcoder.jp/contests/abc340/tasks/abc340_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

unordered_map<ll,ll> m;
ll f(const ll& n) {
    if(n==1)return 0;
    if(m.count(n))return m[n];
    return m[n]=f(n/2)+f((n+1)/2)+n;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    print(f(n));

    return 0;
}
