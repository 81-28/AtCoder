// https://atcoder.jp/contests/abc369/tasks/abc369_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,n;
    cin >> h >> w >> n;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    sort(all(p));
    // cの最長(広義)増加部分列を求める
    // dp[j] : 長さ j+1 の部分列の末尾として可能な最小の c 値(tails)
    // idx[j]: その長さ j+1 を代表する元配列 p のインデックス
    // prev[i]: 元配列 p の i 番目を取ったときの直前の要素のインデックス(復元用)
    vi dp(n,INT_MAX),idx(n,-1),prev(n);
    rep(i,n) {
        auto[r,c]=p[i];
        // non-decreasing(等号を許す)LIS を求めるので upper_bound を使用
        // j は c を置くべき位置(長さ j+1 の末尾にできるかどうか)
        int j=upper_bound(all(dp),c)-dp.begin();
        dp[j]=c;                // tails を更新
        idx[j]=i;               // 長さ j+1 の代表を i にする
        prev[i]=j?idx[j-1]:-1;  // 復元用の前駆を記録
    }
    int m=n-1;
    while (idx[m]==-1) --m;
    v<pii> path;
    // 最長長さを達成する代表 idx[m] から prev を辿って選ばれたコインの位置を復元
    // このループでは選ばれたコインを逆順(末尾から先頭へ)に追加する
    for (int now=idx[m];now!=-1;now=prev[now]) path.pb(p[now]);
    sort(all(path));
    print(path.size());
    path.pb({h,w});
    // 位置から経路を復元
    int x=1,y=1;
    for (auto[r,c]:path) {
        rep(i,r-x) cout<<'D';
        rep(i,c-y) cout<<'R';
        x=r,y=c;
    }
    print();

    return 0;
}
