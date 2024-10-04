// https://atcoder.jp/contests/abc341/tasks/abc341_b

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    long a[n], s[n-1], t[n-1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        cin >> s[i];
        cin >> t[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        long m = a[i] / s[i];
        for (long j = 0; j < m; j++)
        {
            a[i] -= s[i];
            a[i+1] += t[i];
        }
    }
    

    cout << a[n-1] << endl;


    return 0;
}
