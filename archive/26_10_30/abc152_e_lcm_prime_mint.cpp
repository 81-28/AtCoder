// https://atcoder.jp/contests/abc152/tasks/abc152_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
using mint=modint1000000007;
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


unordered_map<int,int> primeFactors(int n) {
    unordered_map<int,int> res;
    if (n<=1) return res;
    while ((n&1) == 0) { ++res[2]; n >>= 1; }
    while (n%3 == 0) { ++res[3]; n /= 3; }
    for (int i=5; i*i <= n; i+=6) {
        while (n%i == 0) { ++res[i]; n /= i; }
        int j = i+2;
        while (n%j == 0) { ++res[j]; n /= j; }
    }
    if (n>1) ++res[n];
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<int,int> mp;
    v<v<pii>> p(n);
    for (auto&q:p) {
        int a;
        cin >> a;
        auto b=primeFactors(a);
        for (auto&[num,cnt]:b) {
            q.pb({num,cnt});
            chmax(mp[num],cnt);
        }
    }
    mint l=1;
    for (auto&[num,cnt]:mp) l*=mint(num).pow(cnt);
    mint ans=0;
    for (auto&q:p) {
        mint res=l;
        for (auto&[num,cnt]:q) res/=mint(num).pow(cnt);
        ans+=res;
    }
    print(ans.val());

    return 0;
}
