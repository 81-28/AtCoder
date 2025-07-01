// https://atcoder.jp/contests/abc213/tasks/abc213_c

// Ctrl + Shift + B       => Build
// Terminal << "./a.out"  => Run

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


vector<int> compress(vector<int> a) {
  int n = a.size();
  map<int,int> mp;
  rep(i,n) mp[a[i]] = 0;
  int id = 1;
  for (auto& p : mp) p.second = id++;
  rep(i,n) a[i] = mp[a[i]];
  return a;
}

int main() {
    int h,w,n;
    cin >> h >> w >> n;


    // me
    // 1つTLE
    // https://chat.openai.com/c/cd3b67ea-2237-446b-a971-0404d810aa07
    int a[n],b[n];
	set<int>aSet;
	set<int>bSet;
    for (int i = 0; i < n; i++)
    {
        cin >>  a[i] >> b[i];
		aSet.insert(a[i]);
		bSet.insert(b[i]);
    }
    vector<int> aVec(aSet.begin(), aSet.end());
    vector<int> bVec(bSet.begin(), bSet.end());
    for (int i = 0; i < n; i++)
    {
        auto aIt = find(aVec.begin(), aVec.end(), a[i]);
        a[i] = distance(aVec.begin(), aIt) + 1;
        auto bIt = find(bVec.begin(), bVec.end(), b[i]);
        b[i] = distance(bVec.begin(), bIt) + 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ' << b[i] <<  endl;
    }


    // https://atcoder.jp/contests/abc213/submissions?f.LanguageName=C%2B%2B&f.Status=AC&f.Task=abc213_c&f.User=&orderBy=created
    // 2番目のを参考
    // https://atcoder.jp/contests/abc213/submissions/24849187

    // vector<int> a(n), b(n);
    // rep(i,n) cin >> a[i] >> b[i];
    // a = compress(a);
    // b = compress(b);
    // rep(i,n) {
    //     printf("%d %d\n", a[i], b[i]);
    // }


    return 0;
}
