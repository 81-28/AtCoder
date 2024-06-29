// https://atcoder.jp/contests/abc340/tasks/abc340_b

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
  int q;
  cin >> q;
  int a[q];
  int n = 0;
  int que[q], xk[q];
  for (int i = 0; i < q; i++)
  {
    cin >> que[i];
    cin >> xk[i];
  }
  for (int i = 0; i < q; i++)
  {
    if (que[i] == 1)
    {
        a[n] = xk[i];
        n++;
    }else{
        cout << a[n-xk[i]] << endl;
    }
  }
  
  return 0;
}
