// https://atcoder.jp/contests/abc341/tasks/abc341_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


class SegmentTree_min {
public:
    vector<int> vec;
    int size=1;
    SegmentTree_min(const int& n) {
        while(size<n)size*=2;
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
    // 要素にアクセスする関数
    int at(const int& pos) {return vec[pos+size];}
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> q >> s;
    // s[i]とs[i+1]が違うかどうか
    SegmentTree_min t(n-1);
    rep(i,n-1) t.update(i,s[i]!=s[i+1]);
    while (q--) {
        int m,l,r;
        cin >> m >> l >> r;
        --l,--r;
        if (m==1) {
            if (l) t.update(l-1,!t.at(l-1));
            if (r+1<n) t.update(r,!t.at(r));
        } else YesNo(t.mi(l,r));
    }

    return 0;
}
