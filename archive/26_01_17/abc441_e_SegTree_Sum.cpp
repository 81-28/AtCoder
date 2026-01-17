// https://atcoder.jp/contests/abc441/tasks/abc441_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return a+b;}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int d=5e5;
    int mx=1e6+1;
    segtree<S,op,e> t(mx);
    int sm=0;
    t.set(sm+d,1);
    int ans=0;
    rep(i,n) {
        if (s[i]=='A') ++sm;
        if (s[i]=='B') --sm;
        ans+=t.prod(0,sm+d);
        t.set(sm+d,t.get(sm+d)+1);
    }
    print(ans);

    return 0;
}
