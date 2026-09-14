// https://atcoder.jp/contests/abc475/tasks/abc475_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    string t;
    cin >> n >> m >> k >> t;
    v<string> s(n);
    int q;
    cin >> s >> q;
    v<pii> p(q);
    for (auto&[x,y]:p) {
        cin >> x >> y;
        --x,--y;
    }

    // 計算量 (v<string>) < (vvi) < (vvb)

    // 正誤状態
    v<string> b(n,string(k,'0'));
    rep(i,n)rep(j,k) b[i][j]+=(s[i][j]==t[j]);
    // ありえる正誤の種類を全列挙
    v<string> bs=b,bb=b;
    for (auto[x,y]:p) {
        bb[x][y]^=1;
        bs.pb(bb[x]);
    }
    // 辞書順にして座標圧縮
    sort(all(bs)),uniq(bs);
    int l=bs.size();
    // その正誤の個数
    v<S> init(l,0);
    for (string bn:b) {
        int idx=lower_bound(all(bs),bn)-bs.begin();
        ++init[idx];
    }
    segtree<S,op,e> seg(init);

    // 未確定者はそこまでの正誤が同じ
    // 脱落は辞書順前から確定、通過は辞書順後ろから確定
    // // 自分より先に確定している正誤は、辞書順で後に位置する

    for (auto[x,y]:p) {
        int idx=lower_bound(all(bs),b[x])-bs.begin();
        seg.set(idx,seg.get(idx)-1);
        b[x][y]^=1;
        idx=lower_bound(all(bs),b[x])-bs.begin();
        seg.set(idx,seg.get(idx)+1);

        int cnt=seg.prod(idx,l);
        // 自分以降の正誤がm以下なら通過
        // m==nでも、全不正解なら通過できない
        YesNo(b[x]!=string(k,'0') && cnt<=m);
    }

    return 0;
}
