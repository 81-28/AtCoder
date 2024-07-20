// https://atcoder.jp/contests/abc363/tasks/abc363_d

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ll n;
    cin >> n;
    if (n <= 10)
    {
        print(n-1);
        return 0;
    }

    int digit = 2;
    vector<ll> quantity = {0,10,9};
    ll sum = 19;
    for (int i = 3; sum < n; i++)
    {
        if (i%2)
        {
            quantity.push_back(quantity[i-1]*10);
        } else {
            quantity.push_back(quantity[i-1]);
        }
        sum += quantity[i];
        digit = i;
    }
    
    ll de = pow(10,digit/2);
    ll num = n - (sum-quantity[digit]);
    string mid = "";
    if (digit%2)
    {
        num += 9;
        mid = to_string(num%10);
        num /= 10;
    }
    num += de/10 - 1;
    print(to_string(num)+mid+reverseString(to_string(num)));


    return 0;
}
