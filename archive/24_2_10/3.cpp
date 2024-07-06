// https://atcoder.jp/contests/arc104/tasks/arc104_a

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
  int a, b;
  cin >> a;
  cin >> b;

  int x = (a+b)/2;
  int y = (a-b)/2;

  cout << x << endl;
  cout << y << endl;

  return 0;
}
