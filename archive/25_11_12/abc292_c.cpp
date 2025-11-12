// https://atcoder.jp/contests/abc292/tasks/abc292_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi cnt(n+1,0);
    rep1(a,n) for(int b=1; a*b<=n; ++b) ++cnt[a*b];
    int ans=0;
    rep1(i,n-1) ans+=cnt[i]*cnt[n-i];
    print(ans);

    return 0;
}
