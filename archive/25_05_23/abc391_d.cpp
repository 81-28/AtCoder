// https://atcoder.jp/contests/abc391/tasks/abc391_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<class T> constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
#define YesNo(x) puts(x?"Yes":"No")
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using pll=pair<ll,ll>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,w;
    cin >> n >> w;
    v<v<pll>> c(w);
    pll p;
    rep(i,n) {
        cin >> p;
        c[--p.f].pb({p.s,i});
    }
    for (auto vec:c) sort(all(vec));
    bool ok=1;
    vll idx(n,-1);
    // 今見ている層が消える暫定時間(デフォは無限)
    vll ans(1,INT_MAX);
    ll mx=0;
    // i層目を見る
    rep(i,n) {
        rep(j,w) {
            // i層のブロックが1つでも無かったら、i以上の層は消えない
            if (i>=c[j].size()) {
                ok=0;
                break;
            }
            // c[j][i].s番のブロックが何層に属しているかを記録
            idx[c[j][i].s]=i;
            chmax(mx,c[j][i].f);
        }
        if (!ok) break;
        // i層目が全部あったら、消える時間を記録
        // i+1層目はi層が消えないと消えられない
        ans[i]=mx++;
        // 次に見る層の暫定時間を設定
        ans.pb(INT_MAX);
    }
    ll q;
    cin >> q;
    rep(j,q) {
        cin >> p;
        ll i=idx[--p.s];
        // 属している層が記録されていないと、それ以前に消えない判定がされている
        YesNo(i==-1 || p.f<ans[i]);
    }

    return 0;
}
