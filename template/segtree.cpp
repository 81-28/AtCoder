#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}



// セグメントツリー（区間最大値）
// 0-indexed, 遅延評価（Lazy Propagation）対応
// 区間の最大値取得・区間一括更新
class SegmentTree_max {
public:
    vector<int> vec,lazy;
    int size=1;
    SegmentTree_max(const int& n) {
        while(size<n)size*=2;
        vec=vector<int>(size*2,INT_MIN);
        lazy=vector<int>(size*2,INT_MIN);
    }
    // 遅延評価の伝播
    // pos: 現在地のノード番号, [a,b): 現在の区間
    void push(const int& pos,const int& a,const int& b) {
        if (lazy[pos]!=INT_MIN) {
            vec[pos]=lazy[pos];
            if (b-a>1) {
                lazy[pos*2]=lazy[pos];
                lazy[pos*2+1]=lazy[pos];
            }
            lazy[pos]=INT_MIN;
        }
    }
    // 区間更新の内部関数
    // [l,r): 更新対象区間, [a,b): 現在の区間, pos: 現在地のノード番号
    void update(const int& l,const int& r,const int& x,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return;
        if (l<=a&&b<=r) {
            lazy[pos]=x;
            push(pos,a,b);
            return;
        }
        int m=(a+b)/2;
        update(l,r,x,a,m,pos*2);
        update(l,r,x,m,b,pos*2+1);
        vec[pos]=max(vec[pos*2],vec[pos*2+1]);
    }
    // 区間 [l,r) を x で一括更新
    void update(const int& l,const int& r,const int& x) {update(l,r,x,0,size,1);}
    // 1点更新
    void update(const int& pos,const int& x) {update(pos,pos+1,x);}
    // 区間 [l,r) の最大値取得
    // [l,r): クエリ区間, [a,b): 現在の区間, pos: 現在地のノード番号
    int query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return INT_MIN;
        if (l<=a&&b<=r) return vec[pos];
        int m=(a+b)/2;
        int ql=query(l,r,a,m,pos*2);
        int qr=query(l,r,m,b,pos*2+1);
        return max(ql,qr);
    }
    // 区間 [l,r) の最大値取得（外部用）
    int mx(const int& l,const int& r) {return query(l,r,0,size,1);}
};

// セグメントツリー（区間最小値）
// 0-indexed, 遅延評価（Lazy Propagation）対応
// 区間の最小値取得・区間一括更新
class SegmentTree_min {
public:
    vector<int> vec,lazy;
    int size=1;
    SegmentTree_min(const int& n) {
        while(size<n)size*=2;
        vec=vector<int>(size*2,INT_MAX);
        lazy=vector<int>(size*2,INT_MAX);
    }
    // 遅延評価の伝播
    // pos: 現在地のノード番号, [a,b): 現在の区間
    void push(const int& pos,const int& a,const int& b) {
        if (lazy[pos]!=INT_MAX) {
            vec[pos]=lazy[pos];
            if (b-a>1) {
                lazy[pos*2]=lazy[pos];
                lazy[pos*2+1]=lazy[pos];
            }
            lazy[pos]=INT_MAX;
        }
    }
    // 区間更新の内部関数
    // [l,r): 更新対象区間, [a,b): 現在の区間, pos: 現在地のノード番号
    void update(const int& l,const int& r,const int& x,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return;
        if (l<=a&&b<=r) {
            lazy[pos]=x;
            push(pos,a,b);
            return;
        }
        int m=(a+b)/2;
        update(l,r,x,a,m,pos*2);
        update(l,r,x,m,b,pos*2+1);
        vec[pos]=min(vec[pos*2],vec[pos*2+1]);
    }
    // 区間 [l,r) を x で一括更新
    void update(const int& l,const int& r,const int& x) {update(l,r,x,0,size,1);}
    // 1点更新
    void update(const int& pos,const int& x) {update(pos,pos+1,x);}
    // 区間 [l,r) の最小値取得
    // [l,r): クエリ区間, [a,b): 現在の区間, pos: 現在地のノード番号
    int query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return INT_MAX;
        if (l<=a&&b<=r) return vec[pos];
        int m=(a+b)/2;
        int ql=query(l,r,a,m,pos*2);
        int qr=query(l,r,m,b,pos*2+1);
        return min(ql,qr);
    }
    // 区間 [l,r) の最小値取得（外部用）
    int mi(const int& l,const int& r) {return query(l,r,0,size,1);}
};

// セグメントツリー（区間和）
// 0-indexed, 遅延評価（Lazy Propagation）対応
// 区間の合計取得・区間一括更新
class SegmentTree_sum {
public:
    vector<int> vec,lazy;
    int size=1;
    SegmentTree_sum(const int& n) {
        while(size<n)size*=2;
        vec=vector<int>(size*2,0);
        lazy=vector<int>(size*2,INT_MAX);
    }
    // 遅延評価の伝播
    // pos: 現在地のノード番号, [a,b): 現在の区間
    void push(const int& pos, const int& a, const int& b) {
        if (lazy[pos]!=INT_MAX) {
            vec[pos]=(b-a)*lazy[pos];
            if (b-a>1) {
                lazy[pos*2]=lazy[pos];
                lazy[pos*2+1]=lazy[pos];
            }
            lazy[pos]=INT_MAX;
        }
    }
    // 区間更新の内部関数
    // [l,r): 更新対象区間, [a,b): 現在の区間, pos: 現在地のノード番号
    void update(const int& l,const int& r,const int& x,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return;
        if (l<=a&&b<=r) {
            lazy[pos]=x;
            push(pos,a,b);
            return;
        }
        int m=(a+b)/2;
        update(l,r,x,a,m,pos*2);
        update(l,r,x,m,b,pos*2+1);
        vec[pos]=vec[pos*2]+vec[pos*2+1];
    }
    // 区間 [l,r) を x で一括更新
    void update(const int& l,const int& r,const int& x) {update(l,r,x,0,size,1);}
    // 1点更新
    void update(const int& pos,const int& x) {update(pos,pos+1,x);}
    // 区間 [l,r) の合計取得
    // [l,r): クエリ区間, [a,b): 現在の区間, pos: 現在地のノード番号
    int query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return 0;
        if (l<=a&&b<=r) return vec[pos];
        int m=(a+b)/2;
        int ql=query(l,r,a,m,pos*2);
        int qr=query(l,r,m,b,pos*2+1);
        return ql+qr;
    }
    // 区間 [l,r) の合計取得（外部用）
    int sm(const int& l,const int& r) {return query(l,r,0,size,1);}
};

template<typename T>
T int_pow(T a,T b) {
    T res=1;
    while(b){if(b&1)res*=a;a*=a;b>>=1;}
    return res;
}
// セグメントツリー（区間積）
// 0-indexed, 遅延評価（Lazy Propagation）対応
// 区間の積取得・区間一括更新
// 型Tはint, long long, atcoder::modint など積演算が定義されている型
template<typename T>
class SegmentTree_prod {
public:
    vector<T> vec,lazy;
    int size=1;
    T identity; // 積の単位元
    SegmentTree_prod(const int& n,T identity_=T(1)):identity(identity_) {
        while(size<n)size*=2;
        vec=vector<T>(size*2,identity);
        lazy=vector<T>(size*2,T());
    }
    // 遅延評価の伝播
    void push(const int& pos,const int& a,const int& b) {
        if (lazy[pos]!=T()) {
            if constexpr (std::is_same<T,int>::value||std::is_same<T,long long>::value) {
                vec[pos]=int_pow(lazy[pos],b-a); // 区間全体をlazy値で埋める
            } else {
                vec[pos]=lazy[pos].pow(b-a); // modint型など
            }
            if (b-a>1) {
                lazy[pos*2]=lazy[pos];
                lazy[pos*2+1]=lazy[pos];
            }
            lazy[pos]=T();
        }
    }
    // 区間更新の内部関数
    void update(const int& l,const int& r,const T& x,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return;
        if (l<=a&&b<=r) {
            lazy[pos]=x;
            push(pos,a,b);
            return;
        }
        int m=(a+b)/2;
        update(l,r,x,a,m,pos*2);
        update(l,r,x,m,b,pos*2+1);
        vec[pos]=vec[pos*2]*vec[pos*2+1];
    }
    // 区間 [l,r) を x で一括更新
    void update(const int& l,const int& r,const T& x) {update(l,r,x,0,size,1);}
    // 1点更新
    void update(const int& pos,const T& x) {update(pos,pos+1,x);}
    // 区間 [l,r) の積取得
    T query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return identity;
        if (l<=a&&b<=r) return vec[pos];
        int m=(a+b)/2;
        T ql=query(l,r,a,m,pos*2);
        T qr=query(l,r,m,b,pos*2+1);
        return ql * qr;
    }
    // 区間 [l,r) の積取得（外部用）
    T pr(const int& l,const int& r) {return query(l,r,0,size,1);}
};



#include <atcoder/modint>
using mint = atcoder::modint998244353;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    SegmentTree_max tmx(n);
    SegmentTree_min tmi(n);
    SegmentTree_sum tsm(n);
    SegmentTree_prod<int> tpr(n); // int型の積
    SegmentTree_prod<mint> tprm(n, mint(1)); // modint型の積
    // 1-indexed
    // SegmentTree_max tmx(n+1);
    rep(i,n) {
        tmx.update(i,a[i]);
        tmi.update(i,a[i]);
        tsm.update(i,a[i]);
        tpr.update(i,a[i]);
        tprm.update(i,mint(a[i]));
        // tmx.update(i+1,a[i]);
    }
    int q,l,r;
    cin >> q;
    rep(i,q) {
        cin >> l >> r;
        print(tmx.mx(l,r));
        print(tmi.mi(l,r));
        print(tsm.sm(l,r));
        print(tpr.pr(l,r));
        print(tprm.pr(l,r).val());
    }

    return 0;
}
