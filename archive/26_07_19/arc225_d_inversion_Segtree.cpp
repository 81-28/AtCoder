// https://atcoder.jp/contests/arc225/tasks/arc225_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    v<S> init(n,0);
    segtree<S,op,e> t(init);
    // 転倒数
    int sm=0;
    rep(i,n) {
        int p;
        cin >> p;
        --p;
        sm+=t.prod(i,n);
        t.set(p,1);
    }
    print(sm);

    return 0;
}
