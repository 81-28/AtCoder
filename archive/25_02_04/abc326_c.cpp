// https://atcoder.jp/contests/abc326/tasks/abc326_c

#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    vll a(n);
    cin >> a;
    sort(all(a));
    ll ans=0;
    auto itl = a.begin(), itr = a.begin();

    bool b=0;
    while (1) {
        for(;itr!=a.end() && *itl+m > *itr; itr++) {}
        if (itr==a.end()) b=1;
        itr--;
        ans = max(ans,(ll)distance(itl,itr)+1);
        if (b) break;
        itl++;
    }
    print(ans);

    return 0;
}