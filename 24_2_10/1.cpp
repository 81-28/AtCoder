// https://atcoder.jp/contests/abc093/tasks/abc093_b

// Ctrl + Shift + B => Build
// Terminal << "./a.out" => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;

int main() {
    int a, b, k;
    cin >> a;
    cin >> b;
    cin >> k;

    for (int i = a; i <= b; i++){
        if (i < a+k || b-k < i){
            cout << i << endl;
        }
        
    }
    
    return 0;
}
