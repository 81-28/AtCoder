// https://atcoder.jp/contests/abc157/tasks/abc157_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return S(a|b);}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> s >> q;
    segtree<S,op,e> t(n);
    rep(i,n) t.set(i,1<<s[i]-'a');
    while (q--) {
        int m;
        cin >> m;
        if (m&1) {
            int i;
            char c;
            cin >> i >> c;
            --i;
            t.set(i,t.get(i)^1<<s[i]-'a');
            s[i]=c;
            t.set(i,t.get(i)^1<<s[i]-'a');
        } else {
            int l,r;
            cin >> l >> r;
            print(__builtin_popcount(t.prod(--l,r)));
        }
    }

    return 0;
}
