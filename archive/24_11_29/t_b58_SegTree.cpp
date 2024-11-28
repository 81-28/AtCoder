// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ee

#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}

class SegmentTree {
public:
    vector<int> vec;
    int size = 1;
    SegmentTree(const int& n) {
        while (size < n) size *= 2;
        // 木構造(三角形)なので要素数はsize*2-1([0]は使わない)
        vec = vector<int>(size*2,1e9);
    }

    void update(int pos, const int& x) {
        // 最も子の要素を更新
        pos = pos + (size-1);
        vec[pos] = x;
        // 親の要素を更新
        while (pos > 1) {
            pos /= 2;
            vec[pos] = min(vec[pos*2],vec[pos*2+1]);
        }
    }

    // [l,r): 求める対象の区間, [a,b): 現在の区間, pos: 現在地の番号
    int query(const int& l, const int& r, const int& a, const int& b, const int& pos) {
        if (r <= a || b <= l) return (int)1e9; // 一切重ならない場合
        if (l <= a && b <= r) return vec[pos]; // 完全に含まれる場合
        // 現在の区間内に境目(l||r)が存在する場合、子の最小値を求める
        int m = (a+b)/2;
        int ql = query(l,r,a,m,pos*2);
        int qr = query(l,r,m,b,pos*2+1);
        return min(ql,qr);
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,l,r,ld,rd;
    cin >> n >> l >> r;
    vi x(n);
    cin >> x;
    SegmentTree t(n);
    t.update(1,0);
    int mi;
    for(int i=1; i<n; i++) {
        ld = lower_bound(all(x),x[i]-r)-x.begin();
        rd = upper_bound(all(x),x[i]-l)-x.begin();
        mi = t.query(ld+1,rd+1,1,t.size+1,1) + 1;
        t.update(i+1,mi);
    }
    // cout<<t.query(n,n+1,1,t.size+1,1)<<'\n';
    cout<<t.vec[n+t.size-1]<<'\n';

    return 0;
}
