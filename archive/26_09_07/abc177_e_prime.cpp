// https://atcoder.jp/contests/abc177/tasks/abc177_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vector<int> primeFactors(int n) {
    vector<int> factors;
    if (n<=1) return factors;
    while ((n&1) == 0) {
        factors.push_back(2);
        n >>= 1;
    }
    while (n%3 == 0) {
        factors.push_back(3);
        n /= 3;
    }
    for (int i=5; i*i <= n; i+=6) {
        while (n%i == 0) {
            factors.push_back(i);
            n /= i;
        }
        int j = i+2;
        while (n%j == 0) {
            factors.push_back(j);
            n /= j;
        }
    }
    if (n>1) factors.push_back(n);
    return factors;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<int,bool> b;
    bool ok=1;
    int g;
    rep(i,n) {
        int a;
        cin >> a;
        if (i) g=gcd(g,a);
        else g=a;
        if (!ok) continue;
        vi f=primeFactors(a);
        sort(all(f));
        uniq(f);
        for (int val:f) {
            if (b[val]) {
                ok=0;
                break;
            }
            b[val]=1;
        }
    }
    if (ok) {
        print("pairwise coprime");
        return 0;
    }
    if (g==1) {
        print("setwise coprime");
        return 0;
    }
    print("not coprime");

    return 0;
}
