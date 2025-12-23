// https://atcoder.jp/contests/joisc2007/tasks/joisc2007_anagra

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    vi fact(n+1,1);
    rep1(i,n) fact[i]=fact[i-1]*i;

    vi cnt(26,0);
    rep(i,n) ++cnt[s[i]-'A'];
    int ans=1;
    rep(i,n-1) {
        rep(c,s[i]-'A') {
            if (!cnt[c]) continue;
            int denom=1;
            rep(j,26) denom*=fact[cnt[j]-(j==c)];
            ans+=fact[n-1-i]/denom;
        }
        --cnt[s[i]-'A'];
    }
    print(ans);

    return 0;
}
