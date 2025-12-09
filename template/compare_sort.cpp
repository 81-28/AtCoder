// compare_sort.cpp
// std::sort やデータ構造での compare（比較関数）の使い方を示すテンプレファイル
// - lambda, 関数オブジェクト(struct), 関数ポインタ
// - pair の二次キーでソートする例

#include <bits/stdc++.h>
using namespace std;

// 関数オブジェクトの例: second を降順、その後 first を昇順
struct BySecondDesc {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.second != b.second) return a.second > b.second; // second の降順
        return a.first < b.first; // tie-breaker: first の昇順
    }
};

bool cmp_func(const pair<int,int>& a, const pair<int,int>& b) {
    return a.first < b.first; // first の昇順
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int,int>> v = {{3,30},{1,40},{2,30},{4,20}};

    // 1) lambda でカスタム比較（second 昇順, first 昇順）
    {
        auto u = v;
        sort(u.begin(), u.end(), [](const auto& a, const auto& b){
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });
        cout << "lambda sort (by second asc, first asc): ";
        for (auto &p: u) cout << "("<<p.first<<","<<p.second<<") ";
        cout << '\n';
    }

    // 2) 関数オブジェクトを使う
    {
        auto u = v;
        sort(u.begin(), u.end(), BySecondDesc());
        cout << "functor sort (BySecondDesc): ";
        for (auto &p: u) cout << "("<<p.first<<","<<p.second<<") ";
        cout << '\n';
    }

    // 3) 関数ポインタを使う
    {
        auto u = v;
        sort(u.begin(), u.end(), cmp_func);
        cout << "function pointer sort (by first asc): ";
        for (auto &p: u) cout << "("<<p.first<<","<<p.second<<") ";
        cout << '\n';
    }

    // 4) 標準の比較関数オブジェクト: std::less / std::greater
    // - sort のデフォルトは std::less<T>()（つまり昇順）
    // - std::greater<T>() を渡すと降順になる（pair では lexicographical 比較が使われる）
    {
        auto u = v;
        // 明示的に std::less を渡す（意味的にはデフォルトと同じ）
        sort(u.begin(), u.end(), std::less<pair<int,int>>());
        cout << "std::less sort (lexicographical asc, same as default): ";
        for (auto &p: u) cout << "("<<p.first<<","<<p.second<<") ";
        cout << '\n';

        u = v;
        // std::greater を渡すと降順（lexicographical の逆）になる
        sort(u.begin(), u.end(), std::greater<pair<int,int>>());
        cout << "std::greater sort (lexicographical desc): ";
        for (auto &p: u) cout << "("<<p.first<<","<<p.second<<") ";
        cout << '\n';

        // priority_queue で最小ヒープを作る例（デフォルトは最大ヒープ）
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_pq;
        for (auto &p: v) min_pq.push(p);
        cout << "priority_queue with greater (min-heap by pair): ";
        while (!min_pq.empty()) { auto p = min_pq.top(); min_pq.pop(); cout << "("<<p.first<<","<<p.second<<") "; }
        cout << '\n';
    }

    // 5) set/map に比較述語を渡す例（順序を変える）
    // - set/map のテンプレート引数に比較関数オブジェクトを渡すと、その順序で内部がソートされる
    // - ここでは BySecondDesc を渡して second の降順で保持する set の例と、
    //   map に std::greater を渡してキーを降順にする例、pair をキーにして second 順で並べる map の例を示す
    {
        set<pair<int,int>, BySecondDesc> s = {{3,30},{1,40},{2,30},{4,20}};
        cout << "set with BySecondDesc (ordered by second desc): ";
        for (auto &p: s) cout << "("<<p.first<<","<<p.second<<") ";
        cout << '\n';

        // map のキーを降順にする例（int キー）
        map<int,string, greater<int>> mp = {{1,"a"},{3,"b"},{2,"c"}};
        cout << "map with greater (keys in descending): ";
        for (auto &kv: mp) cout << "("<<kv.first<<","<<kv.second<<") ";
        cout << '\n';

        // pair をキーにして BySecondDesc を使う例（second が大きい順）
        map<pair<int,int>, string, BySecondDesc> mp2 = {{{1,10},"x"},{{2,20},"y"},{{3,15},"z"}};
        cout << "map<pair,...,BySecondDesc> (ordered by second desc): ";
        for (auto &kv: mp2) cout << "(("<<kv.first.first<<","<<kv.first.second<<")->"<<kv.second<<") ";
        cout << '\n';

        // 補足: std::less<> / std::greater<>（空のテンプレート引数）は C++14 で導入された
        // ポリモーフィックな比較述語で、異なる型同士の比較を安全に行える場面で便利です。
        // 例: std::set<std::string, std::less<>> なら const char* をキーに find できる等。
    }

    // 6) priority_queue にカスタム比較を入れる例
    {
        // second が大きい順に取り出す最大ヒープ (pair の second を優先)
        priority_queue<pair<int,int>, vector<pair<int,int>>, BySecondDesc> pq;
        for (auto &p: v) pq.push(p);
        cout << "priority_queue by second desc pop order: ";
        while (!pq.empty()) { auto p = pq.top(); pq.pop(); cout << "("<<p.first<<","<<p.second<<") "; }
        cout << '\n';
    }

    return 0;
}
