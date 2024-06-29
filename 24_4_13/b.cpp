// https://atcoder.jp/contests/abc349/tasks/abc349_b

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
    string s;
    // 数字を入力
    cin >> s;
    unordered_map<char, int> charCount;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        charCount[ch] = 0; // 初期化
    }
    for (char ch : s) {
        if (isalpha(ch) && islower(ch)) { // 英子文字かつ小文字であることを確認
            charCount[ch]++;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        int charTypesWithCount = 0;
        for (auto& pair : charCount) {
            if (pair.second == i+1) {
                charTypesWithCount++;
            }
        }
        if (charTypesWithCount == 0 || charTypesWithCount == 2)
        {
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


    return 0;
}
