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

    // --- 5) tuple の扱い ---
    // tuple は pair と同様に辞書式比較 (lexicographical) を持つ。要素数が多くても
    // 先頭要素から順に比較される点は pair と同じである。
    vector<tuple<int,int,int>> vt = {{4,450,1},{1,100,2},{4,400,3},{7,700,4},{2,200,5}};
    sort(vt.begin(), vt.end()); // tuple も lexicographical に比較される
    cout << "[lexicographical sort (tuple)] "; for (auto &t: vt) cout << "("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<") "; cout << '\n';

    // first >= 4 の最初の要素を得るには sentinel を使う
    auto it_t = lower_bound(vt.begin(), vt.end(), make_tuple(4, INT_MIN, INT_MIN));
    if (it_t != vt.end()) cout << "lower_bound for first>=4 (tuple) -> ("<<get<0>(*it_t)<<","<<get<1>(*it_t)<<","<<get<2>(*it_t)<<")\n";

    // equal_range で first==4 の範囲を取得
    auto er_t = equal_range(vt.begin(), vt.end(), make_tuple(4, INT_MIN, INT_MIN));
    cout << "equal_range for first==4 (tuple via sentinels):\n";
    for (auto itx = er_t.first; itx != er_t.second; ++itx) cout << "  ("<<get<0>(*itx)<<","<<get<1>(*itx)<<","<<get<2>(*itx)<<")\n";

    // binary_search は tuple 全体の一致を見る点に注意
    cout << "binary_search for (2,200,5): " << (binary_search(vt.begin(), vt.end(), make_tuple(2,200,5))?"yes":"no") << '\n';

    // first のみで扱いたい時はカスタム comparator を使う
    vector<tuple<int,int,int>> by_first_t = vt; // コピー
    stable_sort(by_first_t.begin(), by_first_t.end(), [](const auto& a, const auto& b){ return get<0>(a) < get<0>(b); });
    cout << "[stable_sort by first (tuple)] "; for (auto &t: by_first_t) cout << "("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<") "; cout << '\n';

    auto cmp_tuple_first = [](const tuple<int,int,int>& a, const tuple<int,int,int>& b){ return get<0>(a) < get<0>(b); };
    auto lo_t = lower_bound(by_first_t.begin(), by_first_t.end(), make_tuple(4,0,0), cmp_tuple_first);
    auto hi_t = upper_bound(by_first_t.begin(), by_first_t.end(), make_tuple(4,0,0), cmp_tuple_first);
    cout << "range for first==4 using first-only comparator (tuple):\n";
    for (auto itx = lo_t; itx != hi_t; ++itx) cout << "  ("<<get<0>(*itx)<<","<<get<1>(*itx)<<","<<get<2>(*itx)<<")\n";

    // 注意: pair の場合と同様、ソートと検索で異なる comparator を混在させるのは未定義挙動になる

    // --- 6) まとめ / よくある落とし穴 ---
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

