// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_ac

#include<bits/stdc++.h>
using namespace std;

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

    int n;
    cin >> n;
    vll a(n);
    cin >> a;
    // dp[i] : i日目の最大スコア
    vll dp(n+1);
    dp[1] = a[0];
    dp[2] = a[1];
    for (int i=3; i<=n; i++) {
        dp[i] = max(dp[i-1],dp[i-2]+a[i-1]);
    }
    print(dp[n]);

    return 0;
}
