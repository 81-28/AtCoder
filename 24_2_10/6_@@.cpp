// https://atcoder.jp/contests/abc158/tasks/abc158_d

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
  string s;
  int q;
  cin >> s;
  cin >> q;
  int t[q], f[q];
  string c;
  for (int i = 0; i < q; i++)
  {
    cin >> t[i];
    if(t[i] == 2){
      cin >> f[i];
      cin >> c[i];
    }
  }

  for (int i = 0; i < q; i++)
  {
    if (t[i]==1)
    {
      string news = s;
      for (int j = 0; j < s.length(); j++)
      {
        news[j] = s[s.length()-1-j];
      }
      s = news;
    }else if(t[i]==2){
      if (f[i] == 1)
      {
        s = c[i] + s;
      }else if(f[i] == 2){
        s = s + c[i];
      }
    }
  }
  
  cout << s << endl;

  return 0;
}
