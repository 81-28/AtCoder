// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_q

#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {;
    int n;
    cin >> n;
    vector<int> a(n-1),b(n-2),d(n,0),p(n,-1),ans;
    cin >> a >> b;
    a.insert(a.begin(),0);
    b.insert(b.begin(),0);
    b.insert(b.begin(),0);
    d[1] = a[1];
    p[1] = 0;
    for (int i = 2; i < n; i++)
    {
        if (d[i-1]+a[i] < d[i-2]+b[i])
        {
            d[i] = d[i-1]+a[i];
            p[i] = i-1;
        } else {
            d[i] = d[i-2]+b[i];
            p[i] = i-2;
        }
    }
    ans.push_back(n);
    for (int i = p[n-1]; i >= 0; i = p[i])
    {
        ans.insert(ans.begin(),i+1);
    }
    print(ans.size());
    print(ans);

    return 0;
}
