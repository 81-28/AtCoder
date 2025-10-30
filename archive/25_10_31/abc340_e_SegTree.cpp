// https://atcoder.jp/contests/abc340/tasks/abc340_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
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

    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    // tは1つ左との差を保持
    // t[0]=a[0], t[i]=a[i]-a[i-1]
    // a[i]=[0,i+1)の和
    SegmentTree_sum t(n);
    t.update(0,a[0]);
    for (int i=1; i<n; ++i)  t.update(i,a[i]-a[i-1]);
    while (m--) {
        int b;
        cin >> b;
        // 箱bのボールを取り除く
        int cnt=t.sm(0,b+1);
        int nowb=t.at(b);
        t.update(b,nowb-cnt);
        if (b+1<n) {
            int nowb1=t.at(b+1);
            t.update(b+1,nowb1+cnt);
        }
        // 振り分ける
        int add=cnt/n,r=cnt%n;
        // [begin,end)に+1
        int begin=(b+1)%n,end=(begin+r)%n;
        int nowbe=t.at(begin);
        t.update(begin,nowbe+1);
        int nowen=t.at(end);
        t.update(end,nowen-1);
        // t[0](全体)に+1
        int now0=t.at(0);
        if (end<begin) ++add;
        t.update(0,now0+add);
    }
    vi ans(n);
    ans[0]=t.at(0);
    for (int i=1; i<n; ++i) ans[i]=ans[i-1]+t.at(i);
    print(ans);

    return 0;
}
