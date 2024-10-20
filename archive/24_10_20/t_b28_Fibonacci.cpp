// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_ap
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;cin >> n;
    vector<int> f(n+1);
    f[1]=1;f[2]=1;
    for(int i=3;i<=n;i++) f[i] = (f[i-1]+f[i-2])%(int)(1e9+7);
    cout<<f[n]<<'\n';
}