// https://atcoder.jp/contests/abc364/tasks/abc364_b

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
    int h,w,si,sj;
    cin >> h >> w >> si >> sj;
    vector<string> c(h);
    cin >> c;
    string x;
    cin >> x;

    string wall = "";
    rep(i,w+2) {
        wall += '#';
    }
    rep(i,h) {
        c[i] = '#'+c[i]+'#';
    }
    c.insert(c.begin(),wall);
    c.push_back(wall);

    rep(i,x.size()) {
        if (x[i] == 'L' && c[si][sj-1] != '#')
        {
            sj--;
        }
        if (x[i] == 'R' && c[si][sj+1] != '#')
        {
            sj++;
        }
        if (x[i] == 'U' && c[si-1][sj] != '#')
        {
            si--;
        }
        if (x[i] == 'D' && c[si+1][sj] != '#')
        {
            si++;
        }
    }
    cout << si << ' ' << sj << endl;

    return 0;
}
