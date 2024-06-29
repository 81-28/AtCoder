// https://atcoder.jp/contests/abc342/tasks/abc342_c

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,q;
    string s;
    cin >> n >> s >> q;
    char c, d;
    for (int i = 0; i < q; i++)
    {
        cin >> c >> d;
        for (int j = 0; j < n; j++)
        {
            if(s[j] == c){
                s[j] = d;
            }
        }
    }
    cout << s << endl;
    return 0;
}
