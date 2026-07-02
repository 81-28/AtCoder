// https://atcoder.jp/contests/abc246/tasks/abc246_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
using vvb=v<vb>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,l;
    cin >> n >> l;
    vvb b(n,vb(26,0));
    rep(i,n) {
        string s;
        cin >> s;
        for (char c:s) b[i][c-'a']=1;
    }
    mint ans=0;
    int mx=1LL<<n;
    rep1(i,mx-1) {
        vb bb(26,1);
        int cnt=0;
        rep(j,n) {
            if (!((i>>j)&1)) continue;
            ++cnt;
            rep(k,26) bb[k]=bb[k]&&b[j][k];
        }
        int sm=0;
        rep(k,26) sm+=bb[k];
        if (cnt&1) ans+=mint(sm).pow(l);
        else ans-=mint(sm).pow(l);
    }
    print(ans.val());

    return 0;
}
