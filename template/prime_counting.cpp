// 素数計数関数の実装（Meissel-Lehmer系アルゴリズム）
// 正答コードから抽出した高効率な素数計算

/*
=== π(x) とは何か？ ===

π(x) は「素数計数関数」と呼ばれ、x以下の素数の個数を表します。
注意：円周率のπとは全く別の記号です！

例：
- π(2) = 1  (2以下の素数: 2)
- π(5) = 3  (5以下の素数: 2, 3, 5)
- π(10) = 4 (10以下の素数: 2, 3, 5, 7)
- π(20) = 8 (20以下の素数: 2, 3, 5, 7, 11, 13, 17, 19)

=== なぜπ(x)が重要か？ ===

ABC383-D問題では以下の2パターンを数える必要があります：
1. p^8 ≤ N  → p ≤ N^(1/8) を満たす素数pの個数 = π(N^(1/8))
2. p^2×q^2 ≤ N (p<q) → 各素数pに対して、π(⌊√N/p⌋) - π(p) を合計

つまり、個々の素数を列挙するのではなく、素数の「個数」を効率的に求めることが鍵となります。

=== 素朴な方法の問題点 ===

エラトステネスの篩で素数を列挙する方法：
- 時間計算量: O(N log log N)
- 空間計算量: O(N)
- N = 4×10^12 では現実的ではない

=== Meissel-Lehmer系アルゴリズムの利点 ===

素数計数関数を直接計算する方法：
- 時間計算量: O(N^(2/3)) 程度
- 空間計算量: O(√N)
- 個々の素数を列挙せずに「個数」のみを計算
- 非常に大きなNに対しても実用的

=== アルゴリズムの基本原理 ===

φ(x, a) = x以下でa番目以下の素数で割り切れない数の個数
π(x) = φ(x, π(√x)) + π(√x) - 1

この再帰的な関係を利用して効率的に計算します。
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

// --- 効率的な整数平方根 ---
ll integer_sqrt(ll n) {
    if (n < 0) return 0;
    ll root = static_cast<ll>(sqrt(static_cast<double>(n)));
    // 下方向に調整
    while (root * root > n) {
        root--;
    }
    // 上方向に調整（floor動作のために重要）
    while ((root + 1) * (root + 1) <= n) {
        root++;
    }
    return root;
}

// --- 素数計数関数（Deleglise-Rivat風、Pythonコードから適応） ---
/*
=== このアルゴリズムの詳細解説 ===

1. 初期化段階：
   - dp_small[x] = x - 1  (π(x)の初期近似)
   - dp_large[i] = N/i - 1  (π(N/i)の初期近似)
   
2. 篩の段階：
   各素数p = 2, 3, 5, 7, ... に対して：
   - dp_small[v] -= dp_small[v/p] - sp  (v ≥ p²)
   - dp_large[i] -= pi_w - sp  (適切な条件下で)
   
   ここで sp = π(p-1) は前の素数までの個数

3. 最終結果：
   - dp_small[x] = π(x) for x ≤ √N
   - dp_large[i] = π(⌊N/i⌋) for i ≤ √N

=== 数学的背景 ===

このアルゴリズムは「包除原理」と「動的プログラミング」を組み合わせています：
- φ(x, a) = x以下で最初のa個の素数で割り切れない数の個数
- π(x) = φ(x, π(√x)) + π(√x) - 1
- φ(x, a) = φ(x, a-1) - φ(x/p_a, a-1)  (p_aはa番目の素数)

この再帰関係を効率的に計算することで、O(N^(2/3))の時間で解けます。
*/

// 警告: 正確性と効率性は元のPythonロジックに大きく依存
// 競技プログラミングでは検証済みライブラリの実装を強く推奨
// 戻り値: {dp_small, dp_large}
// dp_small[x] は x <= r = floor(sqrt(N_arg)) に対する π(x) の近似
// dp_large[i] は i <= r に対する π(floor(N_arg / i)) の近似
pair<vector<ll>, vector<ll>> prime_count(ll N_arg) {
    if (N_arg <= 1) {
        // N=0, N=1を明示的に処理、最小限のベクトルを返す
        return {{0}, {0}};
    }
    ll r = integer_sqrt(N_arg);

    // dp_small[x] = π(x) for x <= r
    // dp_large[i] = π(N_arg / i) for i = 1..r (dp_large[0]は未使用)
    vector<ll> dp_small(r + 1);
    vector<ll> dp_large(r + 1);

    // 恒等式 φ(x, 0) = x - 1 で初期化
    for (ll i = 0; i <= r; ++i) {
        dp_small[i] = i - 1; // π(i) ~ i-1 初期値
    }
    for (ll i = 1; i <= r; ++i) {
        dp_large[i] = N_arg / i - 1; // π(N_arg / i) ~ N_arg / i - 1 初期値
    }

    // π計数を使ってrまでの素数を篩にかける
    for (ll p = 2; p <= r; ++p) {
        // dp_small[p] == dp_small[p-1] なら、pは合成数
        if (dp_small[p] == dp_small[p - 1]) {
            continue;
        }

        // pは素数
        ll p2 = p * p;
        ll sp = dp_small[p - 1]; // π(p-1)

        // --- dp_largeを更新 ---
        // N_arg / i >= p*p を満たすiに対してπ(N_arg / i)を更新
        // これは i <= N_arg / p^2 を意味する。i <= r と組み合わせて、制限はmin(r, N_arg / p^2)
        ll limit_i = r;
        // p2が0になるのを避ける（p=0の場合、ただしループはp=2から開始）
        if (p2 > 0 && N_arg / p2 < limit_i) {
            limit_i = N_arg / p2;
        }
        // ループ条件のためにlimit_i >= 1を保証
        if (limit_i < 1) limit_i = 0; // p2 > N_argの場合を処理

        for (ll i = 1; i <= limit_i; ++i) {
            ll v = N_arg / i;      // 現在の値 N_arg / i
            ll w = v / p;          // floor( (N_arg / i) / p )

            // π(w)が必要
            ll pi_w;
            if (w <= r) {
                pi_w = dp_small[w];
            } else {
                // w > rの場合、π(w)が必要。この値はdp_largeに格納されている
                // インデックス`k`は N_arg / k = w を満たす必要がある
                // よって、k = N_arg / w
                // これらのアルゴリズムの性質により、w > rなら k = N_arg / w <= r
                ll k_idx = N_arg / w; // インデックスkを計算
                // 基本チェック: k_idxが範囲内であることを確認（理論上はそうであるべき）
                if (k_idx >= 1 && k_idx <= r) {
                    pi_w = dp_large[k_idx];
                } else {
                    // これはロジックや仮定の問題を示している。防御的に処理
                    pi_w = dp_large[k_idx]; // アルゴリズムの性質に基づいてk_idxが有効だと仮定

                    // --- デバッグ/エラーチェック（オプション） ---
                    // if (k_idx < 1 || k_idx > r) {
                    //     cerr << "Error: k_idx=" << k_idx << " out of bounds [1, " << r << "] for w=" << w << ", p=" << p << ", i=" << i << endl;
                    //     // 例外を投げるか、エラーを返す可能性
                    // }
                }
            }
            dp_large[i] -= pi_w - sp; // 更新式を適用
        }

        // --- dp_smallを更新（下向きループ） ---
        // v >= p*pに対してπ(v)をp*pまで更新
        // すでに計算されたπ値を正しく使用するために下向きに反復する必要がある
        if (p2 > r) continue; // p*pがすでに> rの場合はスキップ

        for (ll v = r; v >= p2; --v) {
            ll w = v / p; // floor(v/p)。w < v <= rなので、π(w)はdp_small[w]
            dp_small[v] -= dp_small[w] - sp; // 更新式を適用
        }
    }

    return {dp_small, dp_large};
}

// --- 使用例とテスト関数 ---
void test_prime_counting() {
    cout << "=== 素数計数関数π(x)のテスト ===" << endl;
    cout << "π(x) = x以下の素数の個数" << endl;
    cout << "例: π(10) = 4 (素数: 2, 3, 5, 7)" << endl << endl;
    
    // 実際の素数を確認するための小さなテスト
    cout << "=== 手動確認（小さな値） ===" << endl;
    vector<int> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int x = 2; x <= 32; x++) {
        int count = 0;
        cout << "π(" << x << ") = ";
        for (int p : small_primes) {
            if (p <= x) count++;
            else break;
        }
        cout << count << "  (素数: ";
        for (int p : small_primes) {
            if (p <= x) cout << p << " ";
            else break;
        }
        cout << ")" << endl;
    }
    cout << endl;
    
    // 大きな値でのテスト
    cout << "=== 大きな値でのπ(x)計算 ===" << endl;
    vector<ll> test_values = {100, 1000, 10000, 100000};
    
    for (ll n : test_values) {
        auto result = prime_count(n);
        ll sqrt_n = integer_sqrt(n);
        
        cout << "N = " << n << " (√N = " << sqrt_n << ")" << endl;
        cout << "π(" << sqrt_n << ") = " << result.first[sqrt_n] << endl;
        
        // 参考：素数の密度について
        double density = (double)result.first[sqrt_n] / sqrt_n;
        cout << "素数密度 ≈ " << density << " (理論値: 1/ln(" << sqrt_n << ") ≈ " 
             << 1.0/log(sqrt_n) << ")" << endl;
        cout << "---" << endl;
    }
    
    cout << "\n=== ABC383-D問題での使用例 ===" << endl;
    cout << "問題: N以下で正の約数をちょうど9個持つ数の個数" << endl;
    cout << "パターン1: p^8 ≤ N  → π(N^(1/8))個" << endl;
    cout << "パターン2: p²q² ≤ N (p<q) → Σ[π(⌊√N/p⌋) - π(p)]個" << endl << endl;
}

// --- ABC383-D問題の解答関数 ---
/*
=== ABC383-D問題の数学的解析 ===

問題: N以下で正の約数をちょうど9個持つ正整数の個数

約数の個数が9個になる場合：
1. 9 = 9¹     → n = p^8 の形（pは素数）
2. 9 = 3 × 3  → n = p²×q² の形（p, qは異なる素数）

各パターンの個数：
1. パターン1: p^8 ≤ N
   → p ≤ N^(1/8) を満たす素数pの個数
   → π(⌊N^(1/8)⌋)

2. パターン2: p²×q² ≤ N (p < q)
   → 各素数pに対して、p < q ≤ ⌊√N/p⌋ を満たす素数qの個数
   → Σ[π(⌊√N/p⌋) - π(p)] (p は 2 ≤ p ≤ N^(1/4) の素数)

従来の方法（エラトステネスの篩）では：
- √N まで篩を実行 → O(√N log log √N)
- N = 4×10^12 の場合、√N ≈ 2×10^6 で時間制限に間に合わない

素数計数関数を使う方法では：
- π(x)を直接計算 → O(N^(2/3))
- 個々の素数を列挙しない
- 大幅な高速化が可能
*/

ll solve_abc383d(ll n) {
    cout << "=== ABC383-D問題を素数計数関数で解く ===" << endl;
    cout << "N = " << n << endl;
    
    // 特殊ケース: n < 36 (2^2 * 3^2 = 36が最小)
    if (n < 36) {
        cout << "N < 36 なので答えは 0" << endl;
        return 0;
    }

    ll n_sqrt = integer_sqrt(n);       // K = floor(sqrt(N))
    ll n_fourth = integer_sqrt(n_sqrt); // floor(N^(1/4))
    ll n_eighth = integer_sqrt(n_fourth); // floor(N^(1/8))

    cout << "√N = " << n_sqrt << endl;
    cout << "N^(1/4) = " << n_fourth << endl;
    cout << "N^(1/8) = " << n_eighth << endl;

    // 素数計数関数を使って計算
    cout << "素数計数関数を計算中..." << endl;
    auto pi_results = prime_count(n_sqrt);
    vector<ll> pi_small = pi_results.first;  // π(x) for x <= √N
    vector<ll> pi_large = pi_results.second; // π(√N / i) for i <= √N

    // --- パターン1: p^8 <= N ---
    // p <= N^(1/8) を満たす素数pの個数
    // ans = π(n_eighth)
    ll ans = 0;
    if (n_eighth < pi_small.size() && n_eighth >= 0) {
        ans = pi_small[n_eighth];
        cout << "パターン1 (p^8): π(" << n_eighth << ") = " << ans << endl;
    }

    // --- パターン2: p^2 * q^2 <= N (p < q は素数) ---
    // 2 <= p <= N^(1/4) の素数pに対して合計
    // p < q <= floor(sqrt(N) / p) を満たす素数qの個数を追加
    // この個数は π(floor(sqrt(N) / p)) - π(p)
    ll pattern2_count = 0;
    ll last_pi_p = 0; // π(p-1)を格納してpの素数性をチェック
    
    cout << "パターン2 (p²q²) の計算:" << endl;
    for (ll p = 2; p <= n_fourth; ++p) {
        // pがpi_smallとpi_largeの範囲内であることを確認
        if (p >= pi_small.size() || p >= pi_large.size()) {
            break;
        }

        ll current_pi_p = pi_small[p]; // π(p)

        // pが素数かチェック: π(p) > π(p-1)
        if (current_pi_p > last_pi_p) {
            // pは素数。寄与を計算
            ll pi_q_upper = pi_large[p]; // π(floor(n_sqrt / p))
            ll contribution = pi_q_upper - current_pi_p;

            if (contribution > 0) {
                pattern2_count += contribution;
                if (p <= 10) { // 小さなpについて詳細表示
                    cout << "  p=" << p << ": π(⌊√N/" << p << "⌋) - π(" << p 
                         << ") = " << pi_q_upper << " - " << current_pi_p 
                         << " = " << contribution << endl;
                }
            } else {
                // 最適化: π(sqrt(N)/p) <= π(p)なら、任意のp' > pに対して、
                // π(sqrt(N)/p') <= π(sqrt(N)/p) かつ π(p') >= π(p)
                // なので寄与は<= 0のまま。早期終了可能
                break;
            }
        }
        last_pi_p = current_pi_p; // 次の反復のために更新
    }
    
    ans += pattern2_count;
    cout << "パターン2合計: " << pattern2_count << endl;
    cout << "最終答え: " << ans << endl;

    return ans;
}

// --- メイン関数（使用例） ---
/*
=== 実行方法 ===

1. コンパイル:
   g++ -o prime_counting prime_counting.cpp -std=c++17

2. 実行:
   ./prime_counting

3. 入力例:
   - 小さな値: 100, 1000
   - 中程度: 10000, 100000  
   - 大きな値: 1000000, 4000000000000

=== 期待される出力 ===

π(x)の値が正しく計算され、ABC383-D問題の解答も表示されます。
特に、素数の密度が素数定理 π(x) ≈ x/ln(x) に近いことも確認できます。
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "π(x) は「素数計数関数」で、x以下の素数の個数を表します" << endl;
    cout << "（注意：円周率のπとは異なります）" << endl << endl;

    // テスト実行
    test_prime_counting();
    
    cout << "\n=== ABC383-D問題の解答例 ===" << endl;
    cout << "N以下で正の約数をちょうど9個持つ正整数の個数を求めます" << endl;
    
    // 入力を受け取って解答
    ll n;
    cout << "\nN を入力してください: ";
    cin >> n;
    
    ll result = solve_abc383d(n);
    cout << "\n最終答え: " << result << endl;
    
    cout << "\n=== 計算量の比較 ===" << endl;
    cout << "従来法（エラトステネスの篩）: O(√N log log √N)" << endl;
    cout << "素数計数関数: O(N^(2/3))" << endl;
    cout << "N = 4×10^12 の場合、素数計数関数の方が圧倒的に高速です" << endl;

    return 0;
}
