// https://atcoder.jp/contests/abc425/tasks/abc425_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t,m;
    cin >> t >> m;
    int mx=5e3;
    vvi nCr(mx+1,vi(mx+1,1));
    for (int n=2; n<=mx; ++n)rep1(r,n-1) {
        nCr[n][r]=(nCr[n-1][r-1]+nCr[n-1][r])%m;
    }
    while (t--) {
        int n;
        cin >> n;
        int ans=1,sm=0;
        while (n--) {
            int c;
            cin >> c;
            sm+=c;
            ans*=nCr[sm][c];
            ans%=m;
        }
        print(ans);
    }

    return 0;
}
