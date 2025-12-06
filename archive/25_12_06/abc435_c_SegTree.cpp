// https://atcoder.jp/contests/abc435/tasks/abc435_c

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


class SegmentTree_max {
public:
    vector<int> vec;
    int size=1;
    SegmentTree_max(const int& n) {
        while(size<n)size*=2;
        vec=vector<int>(size*2,INT_MIN);
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
    // 要素にアクセスする関数
    int at(const int& pos) {return vec[pos+size];}
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    // t[i]:i番目のドミノが倒れた時にギリギリ届かない位置
    SegmentTree_max t(n);
    rep(i,n) t.update(i,i+a[i]);
    int last=0;
    int now=1;
    while (now!=last) {
        last=now;
        now=t.mx(0,now);
    }
    print(min(now,n));

    return 0;
}
