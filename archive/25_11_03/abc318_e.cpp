// https://atcoder.jp/contests/abc318/tasks/abc318_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi idx(n);
    vi add(n,0);
    int ans=0;
    rep(i,n) {
        int a;
        cin >> a;
        --a;
        int m=idx[a].size();
        if (m) {
            int last=idx[a][m-1];
            ans+=add[a]+=m*(i-last-1);
        }
        idx[a].pb(i);
    }
    print(ans);

    return 0;
}
