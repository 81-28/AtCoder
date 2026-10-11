// https://atcoder.jp/contests/abc479/tasks/abc479_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    for (auto&[a,b]:p)  cin >> a;
    for (auto&[a,b]:p)  cin >> b;
    // sを基準にソート、tとの対応は維持
    sort(all(p));
    vi s(n),t(n);
    rep(i,n) {
        auto[a,b]=p[i];
        s[i]=a;
        t[i]=b;
    }

    // 要素が何番目かを記録
    vi tt=t;
    sort(all(tt));
    unordered_map<int,int> idx;
    rep(i,n) idx[tt[i]]=i;
    // 転倒数
    int res=0;
    segtree<S,op,e> seg(n);
    // 空きマスとの交換回数
    int sm=0;
    rep(i,n) {
        auto[a,b]=p[i];
        int j=idx[b];
        res+=seg.prod(j,n);
        seg.set(j,1);
        sm+=abs((a-i)-(b-j));
    }
    print(res+sm);

    return 0;
}
