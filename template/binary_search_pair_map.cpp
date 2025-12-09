// pair_binary_search.cpp
// --- 概要 ---
// vector<pair>/set<pair>/map<> に対する二分探索（lower_bound/upper_bound/binary_search）
// と、pair の second（第二要素）が検索/ソートに与える影響についての実例と解説。

// 主なポイント:
//  - pair のデフォルト比較は lexicographical (first, then second)
//  - first のみで範囲を取りたいときは sentinel を使う (例: {x, INT_MIN} / {x, INT_MAX})
//  - first のみでソート/検索するなら、ソートと検索で同じカスタム comparator を使う
//  - stable_sort を使うと同じ first の要素間で元の相対順序（second の順序）を保持できる

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // サンプルデータ（unsorted の場合を示すため、意図的にバラした順序でも良い）
    vector<pair<int,int>> vp = {{4,450},{1,100},{4,400},{7,700},{2,200}};

    // --- 1) lexicographical (default) にソートして sentinel を使った検索 ---
    sort(vp.begin(), vp.end()); // pair は (first, then second) で比較
    cout << "[lexicographical sort] "; for (auto &p: vp) cout << "("<<p.first<<","<<p.second<<") "; cout << '\n';

    // first >= 4 の最初の要素を得るには、sentinel {4, INT_MIN} を使う
    auto it = lower_bound(vp.begin(), vp.end(), make_pair(4, INT_MIN));
    if (it != vp.end()) cout << "lower_bound for first>=4 -> ("<<it->first<<","<<it->second<<")\n";

    // equal_range を使う（sentinel を使えば first==4 の範囲が得られる）
    auto er = equal_range(vp.begin(), vp.end(), make_pair(4, INT_MIN));
    cout << "equal_range for first==4 (via sentinels):\n";
    for (auto itx = er.first; itx != er.second; ++itx) cout << "  ("<<itx->first<<","<<itx->second<<")\n";

    // binary_search は pair 全体の完全一致をチェックする点に注意
    cout << "binary_search for (2,200): " << (binary_search(vp.begin(), vp.end(), make_pair(2,200))?"yes":"no") << '\n';

    // --- 2) first のみで扱いたい (custom comparator) ---
    // 目的: first のみをキーとして範囲や存在チェックをしたい場合
    vector<pair<int,int>> by_first = vp; // 元データのコピー
    // stable_sort を使うことで、同じ first の要素間では元の second の相対順序が保たれる
    stable_sort(by_first.begin(), by_first.end(), [](const auto& a, const auto& b){ return a.first < b.first; });
    cout << "[stable_sort by first] "; for (auto &p: by_first) cout << "("<<p.first<<","<<p.second<<") "; cout << '\n';

    // 同じ comparator を lower_bound/upper_bound に渡して検索する
    auto cmp_first = [](const pair<int,int>& a, const pair<int,int>& b){ return a.first < b.first; };
    auto lo = lower_bound(by_first.begin(), by_first.end(), make_pair(4, 0), cmp_first);
    auto hi = upper_bound(by_first.begin(), by_first.end(), make_pair(4, 0), cmp_first);
    cout << "range for first==4 using first-only comparator:\n";
    for (auto itx = lo; itx != hi; ++itx) cout << "  ("<<itx->first<<","<<itx->second<<")\n";

    // 注意: ソートと検索で異なる comparator を混在させると未定義挙動になる

    // --- 3) set<pair> の lower_bound ---
    set<pair<int,int>> sp = {{1,10},{3,30},{5,50},{5,55}}; // set は自動で lexicographical にソート
    auto it2 = sp.lower_bound(make_pair(5, INT_MIN));
    if (it2 != sp.end()) cout << "set lower_bound for first>=5 -> ("<<it2->first<<","<<it2->second<<")\n";

    // --- 4) map の lower_bound (キーでの二分探索) ---
    map<int,string> mp = {{1,"a"},{3,"b"},{6,"c"}};
    auto it3 = mp.lower_bound(3);
    if (it3 != mp.end()) cout << "map lower_bound 3 -> ("<<it3->first<<","<<it3->second<<")\n";

    // --- 5) まとめ / よくある落とし穴 ---
    // - pair の second はデフォルトで比較に影響する (同じ first の順序決定に使われる)
    // - first のみで検索したければ sentinel を使うか、ソートと検索で同じ comparator を使う
    // - stable_sort を使うと second の元の相対順序が保たれるため、second の順序が重要な場合に有用


    // --- 補足: .first と ->first の違い ---
    // 基本:
    //  - obj.first : オブジェクト (pair など) のメンバに直接アクセスする時に使う
    //  - ptr->first : ポインタやイテレータが指す要素のメンバにアクセスする時に使う
    //    (ptr->first は (*ptr).first と同じ)
    //
    // よくある場面と注意点:
    //  - イテレータ (例: auto it = vp.begin()) はポインタ風の振る舞いをするため it->first が便利
    //    例: auto it = vp.begin(); cout << it->first; // (*it).first と等価
    //  - range-based for で要素を取得する場合は値コピーなら p.first、参照なら p.first を使える
    //    例: for (auto &p: vp) p.first = 0; // 参照で書き換え可能
    //  - map のイテレータは pair<const Key, T> を返すため it->first は const（変更不可）
    //  - 注意: auto p = *it; のようにコピーしてから p.first = ... としても元のコンテナは変わらない
    //    元の要素を変更したいなら auto &p = *it; と参照を取る必要がある
    //
    // まとめ: イテレータやポインタ風オブジェクトに対しては ->first、直接オブジェクトを持つ変数には .first を使う。
    // コンテナ要素を書き換えるかどうか (コピーか参照か) に注意するのが最も重要。


    return 0;
}

