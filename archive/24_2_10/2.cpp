// https://atcoder.jp/contests/abc114/tasks/abc114_b

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
  string str;
  cin >> str;

  int ans = 1000;
  for (int i = 0; i < str.length()-2; i++)
  {
    int num = (str[i] - '0')*100 + (str[i+1] - '0')*10 + (str[i+2] - '0');
    int diff = abs(753 - num);
    ans = (ans < diff) ? ans : diff;
  }
  
  cout << ans << endl;

  return 0;
}
