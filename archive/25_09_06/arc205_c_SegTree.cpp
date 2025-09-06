// https://atcoder.jp/contests/arc205/tasks/arc205_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


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

    int n;
    cin >> n;
    v<pii> p(n);
    vi num;
    for (auto&[s,t]:p) {
        cin >> s >> t;
        num.pb(s);
        num.pb(t);
    }
    sort(all(num));
    map<int,int> m;
    rep(i,n*2) m[num[i]]=i;
    v<pii> l,r;
    // 左向きの{i,s,t}
    v<tuple<int,int,int>> tu;
    // sm[i]:iまでの累積和
    vi sm(n*2+1,0);
    rep(i,n) {
        auto[a,b]=p[i];
        int s=m[a],t=m[b];
        if (s<t) {
            // 右
            ++sm[s];
            --sm[t+1];
            r.pb({t,i});
        } else {
            tu.pb({i,s,t});
        }
    }
    for (int i=1; i<n*2; ++i) sm[i]+=sm[i-1];
    SegmentTree_sum st(n*2);
    rep(i,n*2) st.update(i,sm[i]);
    for (auto[i,s,t]:tu) {
        int q=st.sm(t,s+1);
        if (q) {
            YesNo(0);
            return 0;
        }
        l.pb({s,i});
    }
    sort(all(l));
    sort(rall(r));
    YesNo(1);
    for (auto[s,i]:l) cout<<i+1<<' ';
    for (auto[t,i]:r) cout<<i+1<<' ';
    print();

    return 0;
}
