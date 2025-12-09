// structured_bindings.cpp
// C++17 の構造化束縛 (structured bindings) の使い方を示すテンプレファイル
// 日本語コメント付きで、pair/tuple/map/array のアンパック例を収録

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // pair の分解
    pair<int, string> p = {1, "one"};
    auto [id, name] = p; // 構造化束縛でアンパック
    cout << "pair -> id=" << id << " name=" << name << '\n';

    // tuple の分解
    tuple<int, double, string> t = {2, 3.14, "pi"};
    auto [ti, td, ts] = t; // tuple も同様に分解可
    cout << "tuple -> " << ti << ", " << td << ", " << ts << '\n';

    // range-based for と組み合わせて map をイテレート
    map<string, int> mp = {{"apple", 3}, {"banana", 5}, {"cherry", 2}};
    for (const auto& [key, val] : mp) {
        // キーと値を個別の変数として扱えるため可読性が高い
        cout << "map: " << key << " -> " << val << '\n';
    }

    // 固定長配列 (std::array) の分解
    array<int, 3> arr = {10, 20, 30};
    auto [a, b, c] = arr; // サイズが一致している必要がある
    cout << "array -> " << a << ", " << b << ", " << c << '\n';

    // 構造化束縛は参照でも受け取れる
    vector<pair<int,int>> v = {{1,100},{2,200}};
    for (auto& [x, y] : v) {
        x += 10; // 参照で受け取ると要素を書き換えられる
    }
    cout << "modified vector pairs: ";
    for (auto const& pr : v) cout << "(" << pr.first << "," << pr.second << ") ";
    cout << '\n';

    return 0;
}
