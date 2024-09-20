// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bg

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


class SegmentTree {
public:
    vector<int> vec;
    int size = 1;
    SegmentTree(const int& n) {
        while (size < n) size *= 2;
        // 木構造(三角形)なので要素数はsize*2-1([0]は使わない)
        vec = vector<int>(size*2,0);
    }

    void update(int pos, const int& x) {
        // 最も子の要素を更新
        pos = pos + (size-1);
        vec[pos] = x;
        // 親の要素を更新
        while (pos > 1) {
            pos /= 2;
            vec[pos] = vec[pos*2] + vec[pos*2+1];
        }
    }

    // [l,r): 求める対象の区間, [a,b): 現在の区間, pos: 現在地の番号
    int query(const int& l, const int& r, const int& a, const int& b, const int& pos) {
        if (r <= a || b <= l) return 0; // 一切重ならない場合
        if (l <= a && b <= r) return vec[pos]; // 完全に含まれる場合
        // 現在の区間内に境目(l||r)が存在する場合、子の合計を求める
        int m = (a+b)/2;
        int ql = query(l,r,a,m,pos*2);
        int qr = query(l,r,m,b,pos*2+1);
        return ql + qr;
    }
};

int main() {
    fastio();

    int n,q;
    cin >> n >> q;
    SegmentTree t(n);
    int c,p,x,l,r;
    rep(i,q) {
        cin >> c;
        if (c == 1) {
            cin >> p >> x;
            t.update(p,x);
        }
        if (c == 2) {
            cin >> l >> r;
            print(t.query(l,r,1,t.size+1,1));
        }
    }

    return 0;
}
