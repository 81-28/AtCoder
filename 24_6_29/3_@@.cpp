// https://atcoder.jp/contests/arc059/tasks/arc059_b

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

int main() {
    int n;
    cin >> n;
    cout << n << endl;


    string strN;
    // 数字を入力
    cin >> strN;
    string newStr = strN;
    rep(i, strN.length()){
        // 文字を数字として扱う
        int num = (strN[i] - '0');
        cout << num << endl;
        // 前後を反転
        newStr[i] = strN[strN.length()-1-i];
    }
    cout << newStr << endl;


    return 0;
}
