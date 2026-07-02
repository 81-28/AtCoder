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
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,m;
    cin >> n >> m;
    // f[i][j]:i,j,(k以下の頂点)を使い、i->jへとたどり着く最短時間
    vvi f(n+1,vi(n+1,INF));
    rep1(i,n) f[i][i]=0;
    while (m--) {
        int a,b,c;
        cin >> a >> b >> c;
        f[a][b]=c;
    }
    int ans=0;
    // 昇順にkを使う場合を考えて、更新できるか考える
    rep1(k,n)rep1(i,n)rep1(j,n) {
        chmin(f[i][j],f[i][k]+f[k][j]);
        ans += f[i][j]==INF ? 0 : f[i][j];
    }
    print(ans);

    return 0;
}
