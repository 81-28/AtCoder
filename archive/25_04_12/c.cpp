// https://atcoder.jp/contests/abc401/tasks/abc401_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll mod=1e9;
    ll n,k;
    cin >> n >> k;
    vll a(n+1,1);
    if (n<k) {
        print(1);
        return 0;
    }
    a[k]=k;
    for (ll i=k+1; i<=n; i++) {
        a[i]=a[i-1]*2-a[i-k-1];
        while (a[i]<0) a[i]+=mod;
        a[i]%=mod;
    }
    print(a[n]);

    return 0;
}
