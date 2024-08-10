// https://atcoder.jp/contests/arc181/tasks/arc181_a

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

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


bool isSorted(const vector<int>& a) {
    vector<int> b = a;
    sort(all(b));
    return a==b;
}
// void sortLR(vector<int> &a, const int& k) {
//     vector<int> l(a.begin(),a.begin()+k),r(a.begin()+k+1,a.end());
//     sort(all(l));
//     sort(all(r));
//     l.push_back(a[k]);
//     l.insert(l.end(),all(r));
//     a = l;
// }

void main2() {
    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;
    if (isSorted(p))
    {
        print(0);
        return;
    }
    if (p[0] == n && p[n-1] == 1)
    {
        print(3);
        return;
    }
    vector<int> maxp(n),minp(n);
    maxp[0] = p[0];
    minp[0] = p[0];
    for (int i = 1; i < n; i++)
    {
        maxp[i] = max(maxp[i-1],p[i]);
        minp[i] = min(minp[i-1],p[i]);
    }
    rep(i,n) {
        if ((i == 0 && p[i] == 1) || (i == n-1 && p[i] == n))
        {
            print(1);
            return;
        } else {
            if (p[i] == i+1 && minp[i-1] == 1 && maxp[i-1] == i)
            {
                print(1);
                return;
            }
        }
    }
    print(2);
    return;
}

int main() {
    int t;
    cin >> t;
    rep(i,t) {
        main2();
    }

    return 0;
}
