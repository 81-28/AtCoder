// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bd

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


struct RollingHash {
    // B個の異なる素数を使ってハッシュを計算
    static constexpr int B = 5;
    static constexpr int mod[B] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};

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
    cout<<fixed<<setprecision(16);

    int n,q;
    string s;
    cin >> n >> q >> s;
    RollingHash h(s);
    while (q--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        auto h1=h.get(a-1,b);
        auto h2=h.get(c-1,d);
        YesNo(h1==h2);
    }

    return 0;
}
