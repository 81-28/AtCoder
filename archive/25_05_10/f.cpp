// https://atcoder.jp/contests/abc405/tasks/abc405_f

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using pll=pair<ll,ll>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


class SegmentTree_min {
public:
    vector<int> vec;
    int size=1;
    SegmentTree_min(const int& n) {
        while(size<n) size*=2;
        vec=vector<int>(size*2,INT_MAX);
    }
    void update(int pos,const int& x) {
        pos+=size-1;
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
    int mi(const int& l,const int& r) {return query(l,r,1,size+1,1);}
};


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    pll p;
    vll sm(n,0);
    rep1(i,m) {
        cin >> p;
        ++sm[p.f/2];
        if (p.s!=n*2) --sm[p.s/2];
    }
    SegmentTree_min t(n);
    t.update(1,0);
    rep1(i,n-1) {
        sm[i]+=sm[i-1];
        t.update(i+1,sm[i]);
    }
    ll q;
    cin >> q;
    ll a,b,mi;
    rep1(i,q) {
        cin >> p;
        p.f/=2,p.s/=2;
        a=sm[p.f],b=sm[p.s];
        mi=t.mi(p.f+1,p.s+2);
        print(a-mi+b-mi);
    }

    return 0;
}
