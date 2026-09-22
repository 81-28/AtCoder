// https://atcoder.jp/contests/abc476/tasks/abc476_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


struct S{
    int mx,mi;
    S(int x,int y) {mx=x,mi=y;}
    S(int x) {mx=mi=x;}
    S(){mx=-INF,mi=INF;}
};
S op(S a,S b){return S(max(a.mx,b.mx),min(a.mi,b.mi));}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi p(n),idx(n+1);
    v<S> init(n);
    rep(i,n) {
        cin >> p[i];
        idx[p[i]]=i;
        init[i]=S(p[i]);
    }
    segtree<S,op,e> t(init);

    while (m--) {
        int l,r;
        cin >> l >> r;
        S res=t.prod(--l,r);
        int i=idx[res.mx],j=idx[res.mi];
        int tmp=p[i];p[i]=p[j],p[j]=tmp;
        idx[p[i]]=i,idx[p[j]]=j;
        t.set(i,S(p[i])),t.set(j,S(p[j]));
    }
    print(p);

    return 0;
}
