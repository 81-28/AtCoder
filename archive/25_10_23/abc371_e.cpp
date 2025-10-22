// https://atcoder.jp/contests/abc371/tasks/abc371_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi idx(n+1,vi(1,0));
    rep1(i,n) {
        int a;
        cin >> a;
        idx[a].pb(i);
    }
    int ans=n*(n*(n-1)/2+n);
    rep1(i,n) {
        idx[i].pb(n+1);
        int m=idx[i].size();
        rep1(j,m-1) {
            int d=idx[i][j]-idx[i][j-1]-1;
            ans-=d*(d-1)/2+d;
        }
    }
    print(ans);

    return 0;
}
