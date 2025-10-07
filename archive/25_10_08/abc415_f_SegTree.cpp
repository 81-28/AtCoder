// https://atcoder.jp/contests/abc415/tasks/abc415_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// 合成
v<pii> merge(v<pii> a,const v<pii>& b) {
    int n=a.size(),m=b.size(),l=n+m;
    if (n && m && a[n-1].f==b[0].f) {
        a[n-1].s+=b[0].s;
        --l;
    }
    for (int i=n+m-l; i<m; ++i) a.pb(b[i]);
    if (l<4) return a;
    pii h=a[0],t=a[l-1];
    int mx=0;
    for (int i=1; i<l-1; ++i) chmax(mx,a[i].s);
    return {h,{0,mx},t};
}

// 区間の連続最大値を求める
// {左,(中央の最大),右}の{文字,数}を返し、連続最大値を返す
// 中央の文字は気にする必要なし
// queryの返り値v(1~3)→結合
class SegmentTree {
public:
    v<v<pii>> vec;
    int size=1;
    SegmentTree(const int& n) {
        while(size<n)size*=2;
        vec=v<v<pii>>(size*2,v<pii>());
    }
    void update(int pos,const int& x) {
        pos+=size;
        vec[pos]={{x,1}};
        while(pos>1) {
            pos/=2;
            vec[pos]=merge(vec[pos*2],vec[pos*2+1]);
        }
    }
    // [l,r): 求める対象の区間, [a,b): 現在の区間, pos: 現在地の番号
    v<pii> query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        if (r<=a||b<=l) return v<pii>(); // 一切重ならない場合
        if (l<=a&&b<=r) return vec[pos]; // 完全に含まれる場合
        // 現在の区間内に境目(l||r)が存在する場合、子の を求める
        int m=(a+b)/2;
        v<pii> ql=query(l,r,a,m,pos*2);
        v<pii> qr=query(l,r,m,b,pos*2+1);
        return merge(ql,qr);
    }
    // [l,r): 求める対象の区間
    int qu(const int& l,const int& r) {
        v<pii> vec=query(l,r,0,size,1);
        int mx=0;
        for (pii p:vec) chmax(mx,p.s);
        return mx;
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string st;
    cin >> n >> q >> st;
    SegmentTree t(n);
    rep(i,n) t.update(i,st[i]-'a');
    while (q--) {
        int m;
        cin >> m;
        if (m==1) {
            int i;
            char x;
            cin >> i >> x;
            t.update(i-1,x-'a');
        }
        if (m==2) {
            int l,r;
            cin >> l >> r;
            print(t.qu(l-1,r));
        }
    }

    return 0;
}
