// https://atcoder.jp/contests/abc330/tasks/abc330_e

#include<bits/stdc++.h>
using namespace std;

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
    int mx;
    SegmentTree_sum(const int& n) {
        mx=n;
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

    int mex() {
        int l=0,r=mx;
        while (l+1<r) {
            int m=(l+r)/2;
            int lsm=sm(l,m);
            if (lsm==m-l) l=m;
            else r=m;
        }
        return l;
    }
};


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    map<int,int> m;
    SegmentTree_sum t(n+2);
    rep(i,n) {
        if (a[i]<n+2 && m[a[i]]==0) t.update(a[i],1);
        ++m[a[i]];
    }
    while (q--) {
        int i,x;
        cin >> i >> x;
        --i;
        --m[a[i]];
        if (a[i]<n+2 && m[a[i]]==0) t.update(a[i],0);
        a[i]=x;
        if (a[i]<n+2 && m[a[i]]==0) t.update(a[i],1);
        ++m[a[i]];
        print(t.mex());
    }

    return 0;
}
