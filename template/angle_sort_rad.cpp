// 整数座標の偏角：+x軸から反時計回りに [0,2π)
// 原点 (0,0) は除外する

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using ld=long double;
const ld PI=acosl(-1);
using pii=pair<int,int>;
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// 偏角が[0,π)にあるか
bool up(const pii& p) {return p.second>0 || (p.second==0 && p.first>0);}
// 外積
// オーバーフローに注意、座標が大きければ`__int128`を使う
int cross(const pii& a,const pii& b) {return a.first*b.second - a.second*b.first;}
// 偏角の昇順、同じ向きは同値
bool comp(const pii& a,const pii& b) {return up(a)!=up(b) ? up(a)>up(b) : cross(a,b)>0;}
// 同じ偏角か（逆方向は別）
bool same(const pii& a,const pii& b) {return !comp(a,b) && !comp(b,a);}

// 方向ベクトルの正規化（(0,0) は不可）
pii norm(const pii& p) {
    const auto&[x,y]=p;
    int g=gcd(x,y);
    return {x/g,y/g};
}

// unordered_map<pii,...> 用（C++17 では pair に標準ハッシュがない）
struct PairHash {
    size_t operator()(const pii& p) const {
        size_t a=hash<int>{}(p.first),b=hash<int>{}(p.second);
        return a^(b+0x9e3779b97f4a7c15ULL+(a<<6)+(a>>2));
    }
};


// ---------- 使い方（p は (0,0) を含まない） ----------
void examples(vector<pii> p) {
    int n=p.size();

    // 1. 偏角ソート
    sort(all(p),comp);
    // same(a,b) で同じ偏角か判定可能

    // 2. 偏角順 map：同じ方向を自動でまとめる（norm 不要）
    map<pii,int,decltype(&comp)> mp(comp);
    for (const pii& a:p) ++mp[a];
    // ※キーは最初に挿入したベクトルのまま（正規化されない）

    // 3. unordered_map：方向を正規化して集計（順序は持たない）
    unordered_map<pii,int,PairHash> cnt;
    for (const pii& a:p) ++cnt[norm(a)];
    // map<pii,int> cnt; として、norm(a) をキーにしてもよい（この場合は辞書順）

    // 4. 2方向 a→b の反時計回り区間 [a,b) を二分探索
    pii a={1,0},b={0,1}; // 境界方向の例
    int l=lower_bound(all(p),a,comp)-p.begin();
    int r=lower_bound(all(p),b,comp)-p.begin();
    int num=same(a,b) ? 0 : (comp(a,b) ? r-l : n-l+r);
    print(num);
    // 0 をまたぐ区間も扱える、a,b が同方向なら空区間とする
    // ちょうど一周 [a,a+2π) は別扱い（全 n 個）

    // 5. 円環を2周分に拡張（例：尺取り用）
    vector<pii> circle=p;
    for (int i=0;i<n;i++) circle.push_back(circle[i]);
    // 2周目の角度に +2π したわけではない
    // circle 全体は comp でソート済みではないので lower_bound 不可

    // 半円の尺取りの実装は ABC481 E を参照
    // ../archive/26_10_25/abc481_e_cross.cpp
}

// 6. 任意の角度幅を数値で加減算するときは atan2l（誤差に注意）
void angle_example(const vector<pii>& p) {
    // 0<=start<2π、0<=width<=2π、角度の境界に厳密性が必要なら整数幾何で判定
    vector<ld> ang;
    for (const auto&[x,y]:p) {
        ld t=atan2l(y,x);
        if (t<0) t+=2*PI;
        ang.push_back(t);
    }
    sort(all(ang));
    int n=ang.size();
    for (int i=0;i<n;i++) ang.push_back(ang[i]+2*PI);

    // 反時計回りの半開区間 [start,start+width) にある点数
    ld start=0,width=PI/2;
    int l=lower_bound(ang.begin(),ang.begin()+n,start)-ang.begin();
    int r=lower_bound(ang.begin()+l,ang.begin()+l+n,start+width)-ang.begin();
    int num=r-l;
    print(num);
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vector<pii> p={{1,2},{2,4},{0,1},{-1,0},{0,-1}};
    examples(p);
    angle_example(p);

    return 0;
}
