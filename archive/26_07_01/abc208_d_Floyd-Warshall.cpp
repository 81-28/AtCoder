// https://atcoder.jp/contests/abc208/tasks/abc208_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/2;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,m;
    cin >> n >> m;
    // f[i][j][k]:i,j,(k以下の頂点)を使い、i->jへとたどり着く最短時間
    v<vvi> f(n+1,vvi(n+1,vi(n+1,INF)));
    rep1(i,n) f[i][i][0]=0;
    while (m--) {
        int a,b,c;
        cin >> a >> b >> c;
        f[a][b][0]=c;
    }
    int ans=0;
    // 昇順にkを使う場合を考えて、更新できるか考える
    rep1(k,n)rep1(i,n)rep1(j,n) {
        ans += (f[i][j][k] = min(f[i][j][k-1], f[i][k][k-1]+f[k][j][k-1]))==INF ? 0 : f[i][j][k];
    }
    print(ans);

    return 0;
}
