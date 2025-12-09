// https://atcoder.jp/contests/abc435/tasks/abc435_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vi c;
// vec[pos] は単純な和ではなく、圧縮区間の幅 (c[b]-c[a]) に対する、
// 区間を使うかどうか0/1 の重み付き和を保持する
class SegmentTree_sum {
public:
    vector<int> vec,lazy;
    int size=1;
    SegmentTree_sum(const int& n) {
        while(size<n)size*=2;
        vec=vector<int>(size*2,0);
        lazy=vector<int>(size*2,INT_MAX);
    }
    // 遅延評価の伝播
    // pos: 現在地のノード番号, [a,b): 現在の区間
    void push(const int& pos, const int& a, const int& b) {
        if (lazy[pos]!=INT_MAX) {
            // ノードが表す区間 [a,b) の幅を座標配列 c を使って計算し、
            // その幅に lazy (0/1) を掛けた値を vec[pos] として保持します。
            // つまり vec[pos] は "区間内で値が1の部分の幅の合計" を表します。
            int w = c[b]-c[a];
            vec[pos]= w*lazy[pos];
            if (b-a>1) {
                // 子ノードにも同様に代入フラグを伝播（代入は上書きなので単純代入で良い）
                lazy[pos*2]=lazy[pos];
                lazy[pos*2+1]=lazy[pos];
            }
            // フラグをクリア
            lazy[pos]=INT_MAX;
        }
    }
    // 区間更新の内部関数
    // [l,r): 更新対象区間, [a,b): 現在の区間, pos: 現在地のノード番号
    void update(const int& l,const int& r,const int& x,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return;
        if (l<=a&&b<=r) {
            // ここで x は 0/1 の代入を表します（区間を使うか使わないか）
            lazy[pos]=x;
            push(pos,a,b);
            return;
        }
        int m=(a+b)/2;
        update(l,r,x,a,m,pos*2);
        update(l,r,x,m,b,pos*2+1);
        vec[pos]=vec[pos*2]+vec[pos*2+1];
    }
    // 区間 [l,r) を x で一括更新
    void update(const int& l,const int& r,const int& x) {update(l,r,x,0,size,1);}
    // 1点更新
    void update(const int& pos,const int& x) {update(pos,pos+1,x);}
    // 区間 [l,r) の合計取得
    // [l,r): クエリ区間, [a,b): 現在の区間, pos: 現在地のノード番号
    int query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return 0;
        if (l<=a&&b<=r) return vec[pos];
        int m=(a+b)/2;
        int ql=query(l,r,a,m,pos*2);
        int qr=query(l,r,m,b,pos*2+1);
        return ql+qr;
    }
    // 区間 [l,r) の合計取得（外部用）
    int sm(const int& l,const int& r) {return query(l,r,0,size,1);}
    // 要素にアクセスする関数
    int at(const int& pos) {return sm(pos,pos+1);}
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    c.pb(0),c.pb(n);
    // 範囲[l,r)とする
    v<pii> p(q);
    for(auto&[l,r]:p) {
        cin >> l >> r;
        --l;
        c.pb(l),c.pb(r);
    }
    // 座標圧縮
    sort(all(c));
    uniq(c);
    unordered_map<int,int> idx;
    // 範囲の個数(nを無視)
    int m=c.size()-1;
    rep(i,m+1) idx[c[i]]=i;

    SegmentTree_sum t(m);
    int ans=n;
    for (auto[l,r]:p) {
        int i=idx[l],j=idx[r];
        int sub=r-l;
        // [i,j)のうち1である部分の、幅の合計
        sub-=t.sm(i,j);
        ans-=sub;
        t.update(i,j,1);
        print(ans);
    }

    return 0;
}
