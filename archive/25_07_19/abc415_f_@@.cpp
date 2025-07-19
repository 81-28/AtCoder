// https://atcoder.jp/contests/abc415/tasks/abc415_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using ull=unsigned long long;
using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
// const pii dir[8]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
// using mint=modint1000000007;
// using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()); // sort後に使用する
#define substring(s,l,r) s.substr(l,r-l)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}
#define YesNo(x) puts(x?"Yes":"No")
// #define f first
// #define s second

// AtCoderでは、inもoutもvector,pair,tuple組み合わせて使えない
template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename... Args>
istream &operator>>(istream &is,tuple<Args...> &t){apply([&is](auto&... args){((is>>args),...);},t);return is;}
template<typename... Args>
ostream &operator<<(ostream &os,const tuple<Args...> &t){apply([&os](const auto&... args){int i=0;((os<<(i++?" ":"")<<args),...);},t);return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

// // pairの足し算
// template<typename F,typename S>
// pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// // pairのデクリメント
// template<typename F,typename S>
// pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}
// // pairと定数の掛け算
// template<typename F,typename S,typename T>
// pair<F,S> operator*(const pair<F,S>& p,const T& a){return{p.f*a,p.s*a};}
// // 定数とpairの掛け算
// template<typename F,typename S,typename T>
// pair<F,S> operator*(const T& a,const pair<F,S>& p){return{a*p.f,a*p.s};}

// セグ木使おう
template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}


// 区間の連続最大値を求める
// {左,中央,右}の{文字,数}を返し、連続最大値を返す
class SegmentTree {
public:
    vector<int> vec;
    int size=1;
    SegmentTree(const int& n) {
        while(size<n)size*=2;
        vec=vector<int>(size*2,0);
    }
    void update(int pos,const int& x) {
        pos+=size-1;
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
        // 現在の区間内に境目(l||r)が存在する場合、子の を求める
        int m=(a+b)/2;
        int ql=query(l,r,a,m,pos*2);
        int qr=query(l,r,m,b,pos*2+1);
        return max(ql,qr);
    }
    // [l,r): 求める対象の区間
    int qu(const int& l,const int& r) {return query(l,r,1,size+1,1);}
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> q >> s;
    SegmentTree t(n);
    rep(i,n-1) {
        t.update(i+1,s[i]-'a');
    }
    while (q--) {
        int m,i,l,r;
        cin >> m;
        if (m==1) {
            char x;
            cin >> i >> x;
            t.update(i+1,s[i]-'a');
        }
        if (m==2) {
            cin >> l >> r;
            print(t.qu(l,r));
        }
    }

    return 0;
}
