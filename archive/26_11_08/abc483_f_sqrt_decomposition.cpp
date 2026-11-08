// https://atcoder.jp/contests/abc483/tasks/abc483_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    const int k=1e3;
    int n;
    cin >> n;
    v<pii> p(n);
    for (auto&[a,b]:p) cin >> a >> b;
    int q;
    cin >> q;
    vi x(q);
    cin >> x;
    int mx=max(x);

    // freq[b][a]：B=b, A=a となる項の個数（b<=K）
    vvi freq(k+1);
    rep1(i,k) freq[i]=vi(i);

    // sub[x]：大きいbの項について、剰余を求める際に引く値の合計
    vi sub(mx+1,0);
    int sm=0,cntBig=0;
    for (auto[a,b]:p) {
        if (b<=k) ++freq[b][a];
        else {
            // (x+a)%b = x+a - b*((x+a)/b)
            // x+aの部分はまとめて計算
            sm+=a;
            ++cntBig;
            // x+aがbの倍数に達するたび、引く値がb増える
            for(int i=b-a;i<=mx;i+=b) sub[i]+=b;
        }
    }
    // 大きいbの項について、各xで引く値を確定
    rep(i,mx) sub[i+1]+=sub[i];

    vi ans(q);
    // 大きいbの項の合計
    rep(i,q) ans[i]=sm+cntBig*x[i]-sub[x[i]];

    // 小さいbの項を、bごとにまとめて計算
    rep1(b,k) {
        // period[r]:B=bの全項について、(r+A)%b の合計
        // 周期bなので、r=0,...,b-1 だけ計算すればよい
        vi period(b,0);
        int cnt=0;
        // r=0 の合計と、B=bの項の個数を求める
        rep(a,b) {
            cnt+=freq[b][a];
            period[0]+=a*freq[b][a];
        }
        if(cnt==0)continue;

        // rを1増やすと全項が1増え、A=b-rの項だけb減る
        rep1(r,b-1) period[r]=period[r-1]+cnt-b*freq[b][b-r];

        // 周期性を利用して、各クエリに加算
        rep(i,q) ans[i]+=period[x[i]%b];
    }
    for (int val:ans) print(val);

    return 0;
}
