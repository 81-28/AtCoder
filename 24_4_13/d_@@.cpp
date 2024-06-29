// https://atcoder.jp/contests/abc349/tasks/abc349_d

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


ll maxNum(ll number) {
    ll mal = floor(log2(number - 1));
    while (number % (ll)pow(2, mal) == 0)
    {
        number--;
    }
    return number;
}

int main() {
    ll m = 1;
    vector<ll> numbers;

    ll l,r;
    cin >> l >> r;
    
    ll mal = floor(log2(r - 1));
    while (maxNum(r) - pow(2, mal) < l)
    {
        if (mal == 0)
        {
            cout << m << '\n' << l << r << endl;
            return 0;
        }
        mal--;
    }
    ll min = pow(2, mal-1);
    ll max = pow(2, mal);
    numbers.push_back(min);
    numbers.push_back(max);

    for (ll i = mal-1; 0 <= i; i--)
    {
        if (min != l)
        {
            min = min - pow(2, i);
            m++;
        }
        if (max != r)
        {
            max = max + pow(2, i);
            m++;
        }
    }
    sort(numbers.begin(), numbers.end());
    cout << m << endl;
    for (ll i = 0; i < m; i++)
    {
        cout << numbers[i] << numbers[i+1] << endl;
    }

    return 0;
}
