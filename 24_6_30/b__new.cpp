// https://atcoder.jp/contests/abc360/tasks/abc360_b

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s,t;
    cin >> s >> t;
    int len = s.size();
    for (int w = 1; w < len; w++)
    {
        string words[w];
        for (int i = 0; i < len; i++)
        {
            words[i%w] += s[i];
        }
        for (int i = 0; i < w; i++)
        {
            if (words[i] == t)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
