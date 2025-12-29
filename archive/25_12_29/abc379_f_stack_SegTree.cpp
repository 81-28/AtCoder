// https://atcoder.jp/contests/abc379/tasks/abc379_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return a+b;}
S e(){return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi h(n);
    cin >> h;
    v<v<pii>> p(n);
    rep(i,q) {
        int l,r;
        cin >> l >> r;
        --l;
        p[l].pb({r,i});
    }
    segtree<S,op,e> t(n);
    stack<int> st;
    vi ans(q,0);
    for (int l=n-1; l>=0; --l) {
        for (auto[r,i]:p[l]) ans[i]=t.prod(r,n);
        int tp;
        while (!st.empty() && h[tp=st.top()]<h[l]) {
            t.set(tp,t.get(tp)-1);
            st.pop();
        }
        st.push(l);
        t.set(l,t.get(l)+1);
    }
    rep(i,q) print(ans[i]);

    return 0;
}
