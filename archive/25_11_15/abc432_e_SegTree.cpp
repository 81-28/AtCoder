// https://atcoder.jp/contests/abc432/tasks/abc432_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


class SegmentTree_sum {
public:
    vector<int> vec;
    int size=1;
    SegmentTree_sum(const int& n) {
        while(size<n)size*=2;
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
    // 要素にアクセスする関数
    int at(const int& pos) {return vec[pos+size];}
};


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    constexpr int mx=5e5;
    SegmentTree_sum t(mx+1);
    SegmentTree_sum ti(mx+1);
    rep(i,n) {
        t.update(a[i],t.at(a[i])+a[i]);
        ti.update(a[i],ti.at(a[i])+1);
    }
    while (q--) {
        int m,l,r;
        cin >> m >> l >> r;
        if (m==1) {
            --l;
            if (a[l]==r) continue;
            t.update(a[l],t.at(a[l])-a[l]);
            ti.update(a[l],ti.at(a[l])-1);
            a[l]=r;
            t.update(a[l],t.at(a[l])+a[l]);
            ti.update(a[l],ti.at(a[l])+1);
        } else {
            if (r<=l) print(n*l);
            else {
                int i=ti.sm(0,l+1);
                int j=ti.sm(r,mx+1);
                int sm=t.sm(l+1,r) + l*i + r*j;
                print(sm);
            }
        }
    }

    return 0;
}
