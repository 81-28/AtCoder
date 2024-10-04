// https://atcoder.jp/contests/abc370/tasks/abc370_a

#include <bits/stdc++.h>
using namespace std;

#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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

    int l,r;
    cin >> l >> r;
    if (l == r) print("Invalid");
    else YesNo(l);

    return 0;
}
