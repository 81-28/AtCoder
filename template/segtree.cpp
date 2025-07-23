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



// セグ木 0-indexed
// max
class SegmentTree_max {
public:
    vector<int> vec;
    int size=1;
    SegmentTree_max(const int& n) {
        while(size<n)size*=2;
        vec=vector<int>(size*2,0);
    }
    void update(int pos,const int& x) {
        pos+=size;
        vec[pos]=x;
        while(pos>1) {
            pos/=2;
            vec[pos]=max(vec[pos*2],vec[pos*2+1]);
        }
    }
    // [l,r): 求める対象の区間, [a,b): 現在の区間, pos: 現在地の番号
    int query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        if (r<=a||b<=l) return INT_MIN; // 一切重ならない場合
        if (l<=a&&b<=r) return vec[pos]; // 完全に含まれる場合
        // 現在の区間内に境目(l||r)が存在する場合、子の最大値を求める
        int m=(a+b)/2;
        int ql=query(l,r,a,m,pos*2);
        int qr=query(l,r,m,b,pos*2+1);
        return max(ql,qr);
    }
    // [l,r): 求める対象の区間
    int mx(const int& l,const int& r) {return query(l,r,0,size,1);}
};

// min
class SegmentTree_min {
public:
    vector<int> vec;
    int size=1;
    SegmentTree_min(const int& n) {
        while(size<n) size*=2;
        vec=vector<int>(size*2,INT_MAX);
    }
    void update(int pos,const int& x) {
        pos+=size;
        vec[pos]=x;
        while(pos>1) {
            pos/=2;
            vec[pos]=min(vec[pos*2],vec[pos*2+1]);
        }
    }
    // [l,r): 求める対象の区間, [a,b): 現在の区間, pos: 現在地の番号
    int query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        if (r<=a||b<=l) return INT_MAX; // 一切重ならない場合
        if (l<=a&&b<=r) return vec[pos]; // 完全に含まれる場合
        // 現在の区間内に境目(l||r)が存在する場合、子の最小値を求める
        int m=(a+b)/2;
        int ql=query(l,r,a,m,pos*2);
        int qr=query(l,r,m,b,pos*2+1);
        return min(ql,qr);
    }
    // [l,r): 求める対象の区間
    int mi(const int& l,const int& r) {return query(l,r,0,size,1);}
};

// sum
class SegmentTree_sum {
public:
    vector<int> vec;
    int size=1;
    SegmentTree_sum(const int& n) {
        while(size<n) size *= 2;
        vec=vector<int>(size*2,0);
    }
    void update(int pos,const int& x) {
        pos+=size;
        vec[pos]=x;
        while(pos>1) {
            pos/=2;
            vec[pos]=vec[pos*2]+vec[pos*2+1];
        }
    }
    // [l,r): 求める対象の区間, [a,b): 現在の区間, pos: 現在地の番号
    int query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        if (r<=a||b<=l) return 0; // 一切重ならない場合
        if (l<=a&&b<=r) return vec[pos]; // 完全に含まれる場合
        // 現在の区間内に境目(l||r)が存在する場合、子の合計を求める
        int m=(a+b)/2;
        int ql=query(l,r,a,m,pos*2);
        int qr=query(l,r,m,b,pos*2+1);
        return ql+qr;
    }
    // [l,r): 求める対象の区間
    int sm(const int& l,const int& r) {return query(l,r,0,size,1);}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    SegmentTree_max tmx(n);
    SegmentTree_min tmi(n);
    SegmentTree_sum tsm(n);
    // 1-indexed
    // SegmentTree_max tmx(n+1);
    // SegmentTree_min tmi(n+1);
    // SegmentTree_sum tsm(n+1);
    rep(i,n) {
        tmx.update(i,a[i]);
        tmi.update(i,a[i]);
        tsm.update(i,a[i]);
        // tmx.update(i+1,a[i]);
        // tmi.update(i+1,a[i]);
        // tsm.update(i+1,a[i]);
    }
    int q,l,r;
    cin >> q;
    rep(i,q) {
        cin >> l >> r;
        print(tmx.mx(l,r));
        print(tmi.mi(l,r));
        print(tsm.sm(l,r));
    }

    return 0;
}
