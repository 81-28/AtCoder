// https://atcoder.jp/contests/abc383/tasks/abc383_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;

    int n_sqrt = sqrt(n);
    int n_eighth = sqrt(sqrt(n_sqrt));

    int m=n_sqrt/2;
    // n^(1/2)/2以下の素数を全て求める
    v<bool> is_prime(m+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i=2; i*i <= m; ++i) {
        if (is_prime[i]) {
            for (int j=i*i; j <= m; j+=i) {
                is_prime[j] = 0;
            }
        }
    }
    vi primes;
    for (int i=2; i <= m; ++i) {
        if (is_prime[i]) primes.pb(i);
    }

    int ans=0;
    for (int p:primes) {
        if (n_eighth < p) break;
        ++ans;
    }

    for (int p:primes) {
        if (p*p > n_sqrt) break;
        int max_q = n_sqrt / p;
        if (p >= max_q) break;
        for (int q:primes) {
            if (p >= q) continue;
            if (q > max_q) break;
            ++ans;
        }
    }
    print(ans);

    return 0;
}
