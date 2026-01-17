// https://atcoder.jp/contests/abc440/tasks/abc440_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return a+b;}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<pii> p(n);
    int mx=0;
    for (auto&[a,b]:p) {
        cin >> a >> b;
        --b;
        chmax(mx,a);
    }
    v<tuple<int,int,int>> t(q);
    for (auto&[w,x,y]:t) {
        cin >> w >> x >> y;
        --w,--y;
        chmax(mx,x);
    }
    ++mx;

    v<multiset<int>> s(2);
    segtree<S,op,e> cnt(mx),sm(mx);
    int ans=0;
    for (auto[a,b]:p) {
        s[b].insert(a);
        cnt.set(a,cnt.get(a)+1);
        sm.set(a,sm.get(a)+a);
        ans+=a;
    }
    for (auto[w,x,y]:t) {
        auto&[a,b]=p[w];
        s[b].erase(s[b].find(a));
        cnt.set(a,cnt.get(a)-1);
        sm.set(a,sm.get(a)-a);
        ans-=a;
        a=x,b=y;
        s[b].insert(a);
        cnt.set(a,cnt.get(a)+1);
        sm.set(a,sm.get(a)+a);
        ans+=a;

        // 2の個数だけスコアを倍にできる
        // 倍にするスコアは大きい順に貪欲に採用
        // 採用したものが全て2であると、ループになってしまうので、2の最小の代わりに1の最大を採用
        // 1が無い場合も考慮する必要あり
        int cnt0=s[0].size(),cnt1=s[1].size();
        bool add=0;
        if ((cnt0 && cnt1 && *s[0].rbegin()<*s[1].begin()) || !cnt0) {
            --cnt1;
            add=1;
        }
        // [l,r) : 上から見た個数の和が、rでcnt1未満,lでcnt1以上となる様に二分探索
        int l=0,r=mx;
        while (l+1<r) {
            int m=(l+r)/2;
            int cntm=cnt.prod(m,mx);
            if (cnt1>cntm) r=m;
            else l=m;
        }
        int cntr=cnt.prod(r,mx);
        int sm1=sm.prod(r,mx)+l*(cnt1-cntr);
        if (add && cnt0) sm1+=*s[0].rbegin();
        print(ans+sm1);
    }

    return 0;
}
