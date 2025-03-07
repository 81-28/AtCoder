// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ef

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


class SegmentTree {
public:
    vector<int> vec;
    int size = 1;
    SegmentTree(const int& n) {
        while (size < n) size *= 2;
        vec = vector<int>(size*2,0);
    }

    void update(int pos, const int& x) {
        pos = pos + (size-1);
        vec[pos] = x;
        while (pos > 1) {
            pos /= 2;
            vec[pos] = vec[pos*2] + vec[pos*2+1];
        }
    }

    // [l,r): 求める対象の区間, [a,b): 現在の区間, pos: 現在地の番号
    int query(const int& l, const int& r, const int& a, const int& b, const int& pos) {
        if (r <= a || b <= l) return 0;
        if (l <= a && b <= r) return vec[pos];
        int m = (a+b)/2;
        int ql = query(l,r,a,m,pos*2);
        int qr = query(l,r,m,b,pos*2+1);
        return ql + qr;
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    SegmentTree t(n);
    t.update(a[n-1],1);
    ll ans=0;
    for (int i=n-2; i>=0; i--) {
        ans += t.query(1,a[i],1,t.size+1,1);
        t.update(a[i],1);
    }
    print(ans);

    return 0;
}
