// https://atcoder.jp/contests/abc343/tasks/abc343_f

#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


class SegmentTree_max2 {
public:
    vector<pair<pii,pii>> vec;
    int size=1;
    SegmentTree_max2(const int& n) {
        while(size<n)size*=2;
        vec=vector<pair<pii,pii>>(size*2,{{0,0},{0,0}});
    }
    void update(int pos,const int& x) {
        pos+=size;
        vec[pos]={{x,1},{0,0}};
        while(pos>1) {
            pos/=2;
            map<int,int> m;
            auto[p1,p2]=vec[pos*2];
            m[p1.f]+=p1.s;
            m[p2.f]+=p2.s;
            auto[p3,p4]=vec[pos*2+1];
            m[p3.f]+=p3.s;
            m[p4.f]+=p4.s;
            auto it=m.rbegin();
            pii p=*it;
            ++it;
            pii q=*it;
            vec[pos]={p,q};
        }
    }
    // [l,r): 求める対象の区間, [a,b): 現在の区間, pos: 現在地の番号
    pair<pii,pii> query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        if (r<=a||b<=l) return {{0,0},{0,0}}; // 一切重ならない場合
        if (l<=a&&b<=r) return vec[pos]; // 完全に含まれる場合
        // 現在の区間内に境目(l||r)が存在する場合、子の最大値を求める
        int mid=(a+b)/2;
        map<int,int> m;
        auto[p1,p2]=query(l,r,a,mid,pos*2);
        m[p1.f]+=p1.s;
        m[p2.f]+=p2.s;
        auto[p3,p4]=query(l,r,mid,b,pos*2+1);
        m[p3.f]+=p3.s;
        m[p4.f]+=p4.s;
        auto it=m.rbegin();
        pii p=*it;
        ++it;
        pii q=*it;
        return {p,q};
    }
    // [l,r): 求める対象の区間
    pair<pii,pii> mx2(const int& l,const int& r) {return query(l,r,0,size,1);}
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    // {{一番大きい数,個数},{二番目に大きい数,個数}}
    SegmentTree_max2 t(n);
    rep(i,n) {
        int a;
        cin >> a;
        t.update(i,a);
    }
    while (q--) {
        int m;
        cin >> m;
        if (m==1) {
            int p,x;
            cin >> p >> x;
            --p;
            t.update(p,x);
        }
        if (m==2) {
            int l,r;
            cin >> l >> r;
            print(t.mx2(l-1,r).s.s);
        }
    }

    return 0;
}
