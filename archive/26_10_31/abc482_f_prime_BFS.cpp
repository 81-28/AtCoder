// https://atcoder.jp/contests/abc482/tasks/abc482_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vector<int> primeFactors(int n) {
    vector<int> factors;
    if (n<=1) return factors;
    while ((n&1) == 0) {
        factors.push_back(2);
        n >>= 1;
    }
    while (n%3 == 0) {
        factors.push_back(3);
        n /= 3;
    }
    for (int i=5; (ll)i*i <= n; i+=6) {
        while (n%i == 0) {
            factors.push_back(i);
            n /= i;
        }
        int j = i+2;
        while (n%j == 0) {
            factors.push_back(j);
            n /= j;
        }
    }
    if (n>1) factors.push_back(n);
    return factors;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    if (n==1) {
        rep(i,m) print(i==1%m?1:-1);
        return 0;
    }

    vi g=primeFactors(n);
    for (int&val:g) val%=m;
    int l=g.size();

    // d[i][num]:次にg[i]をかけ、余りがnumとなる時の最小
    vvi d(l,vi(m,INF));
    // {gのidx,余り}
    queue<pii> q;
    d[0][1%m]=0;
    q.push({0,1%m});
    // gを1周すると、nの1乗分の約数で行ける範囲
    while (!q.empty()) {
        auto[i,num]=q.front();
        q.pop();
        int j=(i+1)%l;
        // 掛けるかどうかの2パターンの遷移
        rep(b,2) {
            int nxt=num;
            if (b) nxt=num*g[i]%m;
            if (d[j][nxt]!=INF) continue;
            d[j][nxt]=d[i][num]+1;
            q.push({j,nxt});
        }
    }
    for (int val:d[0]) print(val==INF?-1:max(1LL,val/l));

    return 0;
}
