// https://atcoder.jp/contests/abc468/tasks/abc468_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rall(v) v.rbegin(),v.rend()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


struct RollingHash {
    // B個の異なる素数を使ってハッシュを計算
    static constexpr int B = 3;
    static constexpr int mod[B] = {998244353, 1000000007, 1000000009};

    // 実体を定義・初期化
    inline static int base[B];
    inline static bool is_initialized = false;

    vector<array<long long, B>> hash, power;

    // コンストラクタ：O(N)で前計算
    RollingHash(const string& S) {
        // 実行時に一度だけ基数をランダムに初期化
        if (!is_initialized) {
            mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
            for (int i=0; i<B; ++i) base[i] = rng() % (mod[i] - 2) + 2;
            is_initialized = true;
        }

        int n = S.size();
        hash.assign(n+1, array<long long, B>{});
        power.assign(n+1, array<long long, B>{});
        
        for (int i=0; i<B; ++i) power[0][i] = 1;

        for (int i=0; i<n; ++i) {
            for (int j=0; j<B; ++j) {
                hash[i+1][j] = (hash[i][j] * base[j] + S[i]) % mod[j];
                power[i+1][j] = (power[i][j] * base[j]) % mod[j];
            }
        }
    }

    // O(1)で区間 [l, r) のハッシュ値を取得 (0-indexed)
    array<long long, B> get(int l, int r) const {
        array<long long, B> res;
        for (int j=0; j<B; ++j) {
            res[j] = hash[r][j] - hash[l][j] * power[r-l][j] % mod[j];
            if (res[j] < 0) res[j] += mod[j];
        }
        return res;
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    string t(rall(s));
    RollingHash hs(s), ht(t);

    auto solve=[&](auto self,int i,int j,int k) {
        int len=min(i,n-j);
        int l=0;
        int r=len+1;
        while (l+1<r) {
            int m=(l+r)/2;
            if (hs.get(j,j+m)==ht.get(n-i,n-i+m)) l=m;
            else r=m;
        }
        if (l==len || k==1) return l;
        return l+1+self(self,i-l-1,j+l+1,k-1);
    };

    int ans=0;
    rep(c,n) ans += 1+solve(solve,c,c+1,2);
    rep1(c,n-1) ans += solve(solve,c,c,2);
    print(ans);

    return 0;
}
