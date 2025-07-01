// https://atcoder.jp/contests/abc376/tasks/abc376_c

#include <bits/stdc++.h>
using namespace std;

#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    fastio();

    int n;
    cin >> n;
    vi a(n),b(n-1);
    cin >> a >> b;
    sort(all(a));
    multiset<int> bs(all(b));
    int ans = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        auto itB = bs.lower_bound(a[i]);
        if (itB == bs.end()) {
            if (ans == INT_MAX) {
                ans = a[i];
            } else {
                print(-1);
                return 0;
            }
        } else {
            bs.erase(itB);
        }
    }
    if(ans == INT_MAX) print(a[0]);
    else print(ans);

    return 0;
}
