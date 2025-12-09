// v[x] => v.at()
template<typename T>
class v:public vector<T> {
public:
    using vector<T>::vector;
    T&operator[](size_t index){return this->at(index);}
    const T&operator[](size_t index)const{return this->at(index);}
};


// 配列の操作
#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    // 配列の要素にアクセス
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    // ※ 配列の添字アクセスは O(1)
    std::cout << std::endl; // 1 2 3 4 5

    return 0;
}



// ベクトル（動的配列）
// メリット: 要素へのランダムアクセスがO(1)
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 要素の追加
    vec.push_back(6);
    // push_back: amortized O(1)（容量が足りない場合は再割当が発生して O(n) になる）

    // 要素へのアクセス
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    // vec[i] のアクセスは O(1)
    std::cout << std::endl; // 1 2 3 4 5 6


    // 3行5列の二次元ベクトルを全て0で初期化
    int rows = 3;
    int cols = 5;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
    // 初期化に O(rows * cols)

    // 動的にサイズを決める
    int rows = 3;
    int cols = 5;
    // 行を確保
    std::vector<std::vector<int>> matrix;
    matrix.resize(rows);
    // 各行の列を確保し、初期化
    for (int i = 0; i < rows; ++i) {
        matrix[i].resize(cols, 0);  // 全て0で初期化
    }
    // resize のコストは新しい要素分の初期化に依存（各行で O(cols)）

    // 末尾の要素を削除
    vec.pop_back();
    // pop_back: O(1)

    // ベクトルが空かどうかを確認
    if (vec.empty()) {
        std::cout << "Vector is empty" << std::endl;
    }

    // 3以上の最小の要素(ソート済みでないと正しい結果は得られない)
    auto it = lower_bound(vec.begin(), vec.end(), 3);
    // lower_bound: binary search -> O(log n) （要素はソート済みである必要がある）
    // 距離(index)を求める
    std::cout << distance(vec.begin(),it) << std::endl;
    // std::distance on random-access iterator: O(1); on other iterators: O(n)

    // 3番目の位置に10を挿入
    vec.insert(vec.begin() + 2, 10);
    // insert at arbitrary position in vector: O(n) (要素を移動させるため)

    // 3番目の要素を削除 (インデックスは2)
    vec.erase(vec.begin() + 2);
    // erase at arbitrary position in vector: O(n)

    // 値が2の要素を全て削除
    vec.erase(std::remove(vec.begin(), vec.end(), 2), vec.end());
    // erase-remove idiom: std::remove O(n) + erase O(k) -> 全体 O(n)

    // 2番目から4番目の要素を削除 (インデックスは1から3)
    vec.erase(vec.begin() + 1, vec.begin() + 4);
    // erase(range) on vector: O(n) for shifting elements after range

	// 配列の重複を消す
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
    // unique は隣接要素の比較で O(n)（事前に sort しておくと効果的）

    // 全ての要素を削除
    vec.clear();
    // clear: O(n) で要素を破棄（デストラクタ呼び出しが発生する場合）

    return 0;
}


// 切り取る方法
#include <iostream>
#include <vector>
#include <algorithm> // std::copy

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int start = 2;
    int end = 5;
    // インデックス2から4まで
    std::vector<int> slicedVec(vec.begin() + start, vec.begin() + end);
    // 範囲コピー: コピーする要素数 k に対して O(k)

    std::cout << "Sliced vector: ";
    for (int val : slicedVec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}


// 標準ライブラリのソート
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 3, 1, 4, 2};

    // ソート
    std::sort(vec.begin(), vec.end());
    // sort: O(n log n)

    // ソート後の出力
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl; // 1 2 3 4 5

    return 0;
}


// アルゴリズム
#include <iostream>
#include <algorithm> // std::max_element
#include <vector>
#include <numeric> // std::accumulate

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 検索
    auto it = std::find(vec.begin(), vec.end(), 3);
    // std::find: linear search O(n)
    if (it != vec.end()) {
        std::cout << "Found 3 at position " << std::distance(vec.begin(), it) << std::endl;
    }

    // 逆順
    std::reverse(vec.begin(), vec.end());
    // reverse: O(n)
    for (int i : vec) {
        std::cout << i << " "; // 5 4 3 2 1
    }
    std::cout << std::endl;

    // 合計
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    long long sumLL = std::accumulate(vec.begin(), vec.end(), 0LL);
    // accumulate: O(n)
    std::cout << "Sum: " << sum << std::endl; // Sum: 15

    // 最大値
    int maxElement = *std::max_element(vec.begin(), vec.end());
    // max_element: O(n)
    std::cout << "Max element: " << maxElement << std::endl; // Max element: 5

    // 最大値のイテレータを取得
    auto maxElementIter = std::max_element(vec.begin(), vec.end());

    // インデックスを計算
    int maxIndex = std::distance(vec.begin(), maxElementIter);

    std::cout << "Maximum value in the vector: " << *maxElementIter << std::endl;
    std::cout << "Index of maximum value: " << maxIndex << std::endl;

    return 0;
}


// 横に結合する
#include <vector>
#include <iostream>

// 横に結合する関数
std::vector<std::vector<int>> concatenateHorizontally(const std::vector<std::vector<int>>& vec1, const std::vector<std::vector<int>>& vec2) {
    // vec1とvec2の行数が同じであることを確認
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("Vectors must have the same number of rows to concatenate horizontally.");
    }

    std::vector<std::vector<int>> result(vec1.size());

    for (size_t i = 0; i < vec1.size(); ++i) {
        // vec1とvec2の行を連結
        result[i].reserve(vec1[i].size() + vec2[i].size());
        result[i].insert(result[i].end(), vec1[i].begin(), vec1[i].end());
        result[i].insert(result[i].end(), vec2[i].begin(), vec2[i].end());
    }

    // 全体コスト: 各行の連結に要する時間は各行の長さに比例するため、合計で O(total elements)

    return result;
}

// デモンストレーション用の関数
void print2DVector(const std::vector<std::vector<int>>& vec) {
    for (const auto& row : vec) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> vec1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> vec2 = {{7, 8}, {9, 10}};

    try {
        std::vector<std::vector<int>> result = concatenateHorizontally(vec1, vec2);
        print2DVector(result);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


// 縦に結合する
#include <vector>
#include <iostream>

// 縦に結合する関数
std::vector<std::vector<int>> concatenateVertically(const std::vector<std::vector<int>>& vec1, const std::vector<std::vector<int>>& vec2) {
    std::vector<std::vector<int>> result = vec1;

    // vec2をresultに追加
    result.insert(result.end(), vec2.begin(), vec2.end());

    return result;
}

// デモンストレーション用の関数
void print2DVector(const std::vector<std::vector<int>>& vec) {
    for (const auto& row : vec) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> vec1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> vec2 = {{7, 8, 9}, {10, 11, 12}};

    std::vector<std::vector<int>> result = concatenateVertically(vec1, vec2);
    print2DVector(result);

    return 0;
}


// reserveは、C++のstd::vectorにおいて、将来の要素の追加に備えて内部のバッファのサイズを事前に確保するためのメソッドです。
// これにより、頻繁なメモリ再割り当てを避け、パフォーマンスを向上させることができます。
// reserveの使い方
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec;
    
    // 事前に10個分のメモリを確保
    vec.reserve(10);

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
        std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    }

    return 0;
}

// reserveの効果
// メモリ再割り当ての削減: ベクトルに新しい要素が追加されると、内部バッファの容量を超える場合にメモリが再割り当てされます。reserveを使用すると、あらかじめ十分な容量を確保することで、頻繁な再割り当てを防げます。
// パフォーマンスの向上: 再割り当てが発生すると、既存の要素を新しいメモリ領域にコピーする必要があります。これを回避することで、要素の追加操作のパフォーマンスが向上します。

// 注意点
// サイズは変わらない: reserveは容量を確保するだけで、ベクトルのサイズ（要素数）は変わりません。サイズは依然として0のままです。
// メモリの無駄遣い: 必要以上に大きな容量を確保すると、メモリを無駄に消費する可能性があります。reserveを使用する場合は、予測される要素数に基づいて適切な値を指定しましょう。
// reserveとresizeの違い
// reserve: 容量を変更するだけで、要素数は変更しません。新しい要素の追加に備えてメモリを確保します。
// resize: 要素数を変更します。新しい要素はデフォルト値で初期化されます。
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec;
    vec.reserve(10); // 容量を10に確保

    // reserve は容量を確保するだけで O(1)、その後の push_back は再割当がなければ amortized O(1)

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
        std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    }

    return 0;
}



// pair
#include <iostream>
#include <utility>  // pairを使用するためのヘッダファイル

using namespace std;

int main() {
    // pairの作成
    pair<int, string> p1;
    p1.first = 1;  // firstに値を設定
    p1.second = "apple";  // secondに値を設定

    // 初期化リストを使ったpairの作成
    pair<int, string> p2(2, "banana");

    // make_pairを使ったpairの作成
    pair<int, string> p3 = make_pair(3, "cherry");

    // pairの出力
    cout << p1.first << ": " << p1.second << endl; // 1: apple
    cout << p2.first << ": " << p2.second << endl; // 2: banana
    cout << p3.first << ": " << p3.second << endl; // 3: cherry

    // 比較 (firstが優先される)
    if (p1 < p2) {
        cout << "p1 is less than p2" << endl; // p1 is less than p2
    }
    // pair の比較は定数時間 O(1)

    return 0;
}



// マップ (連想配列)
// メリット: キーによる高速な要素検索、追加、削除 (平均O(log n))

// map はキーと値のペアを保持する連想コンテナで、内部的に赤黒木を使用しています。
// 順序: キーに基づいて要素が常にソートされた状態で保持される。
// 操作の時間計算量: 平均して O(log n) の時間で要素の検索、挿入、削除が行われる。
// 使用例: 順序が必要な場合（例えば、辞書順に要素を保持したい場合）。
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> myMap;
    myMap["one"] = 1;
    myMap["two"] = 2;

    // map の検索/挿入/削除は O(log n)

    // 要素へのアクセス
    std::cout << "one: " << myMap["one"] << std::endl; // one: 1
    std::cout << "two: " << myMap["two"] << std::endl; // two: 2


    // mapの初期化
    std::map<std::string, int> m;
    m["apple"] = 1;
    m["banana"] = 2;
    m["cherry"] = 3;

    // mapの要素を全て出力する方法
    for (const auto &pair : m) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 要素が存在するかどうかの判定
    // find()
    auto it = m.find("apple");
    if (it != m.end()) {
        // キーが存在する場合の処理
        std::cout << "apple exists." << std::endl;
    } else {
        // キーが存在しない場合の処理
        std::cout << "apple does not exist." << std::endl;
    }

    // count()
    if (m.count("apple") > 0) {
        // キーが存在する場合の処理
        std::cout << "apple exists." << std::endl;
    } else {
        // キーが存在しない場合の処理
        std::cout << "apple does not exist." << std::endl;
    }


    return 0;
}



// ハッシュマップ (unordered_map)
// メリット: キーによる非常に高速な要素検索、追加、削除 (平均O(1))

// unordered_map はハッシュテーブルを使用する連想コンテナです。
// 順序: 要素は順序を持たない。
// 操作の時間計算量: 平均して O(1) の時間で要素の検索、挿入、削除が行われる。
// 使用例: 要素の順序が不要で、効率的な検索、挿入、削除が必要な場合。
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // unordered_mapの宣言
    unordered_map<string, int> umap;

    // 要素の追加
    umap["apple"] = 1;
    umap["banana"] = 2;

    // unordered_map の平均コストは O(1)（ハッシュ衝突で悪化する場合がある）

    // 要素の検索
    if (umap.find("apple") != umap.end()) {
        cout << "apple found: " << umap["apple"] << endl; // apple found: 1
    }

    // 要素の削除
    umap.erase("banana");

    // 全ての要素を出力
    for (const auto &pair : umap) {
        cout << pair.first << ": " << pair.second << endl; // apple: 1
    }
    // 順序は保証されない

    return 0;
}



// スタック (LIFO)
// メリット: 末尾の要素をO(1)で取得・削除
#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // 要素の追加
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // 要素の取り出し
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    // stack::push/pop/top は O(1)
    std::cout << std::endl; // 3 2 1

    return 0;
}



// キュー (FIFO)
// メリット: 先頭の要素をO(1)で取得・削除
#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // 要素の追加
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // 要素の取り出し
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    // queue::push/pop/front は O(1)
    std::cout << std::endl; // 1 2 3

    return 0;
}



// 優先度付きキュー
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> pq;

    // デフォルト(降順)
    priority_queue<int, vector<int>, less<int>> T;
    // これを使うと逆順(昇順)
    priority_queue<int, vector<int>, greater<int>> T;

    // 要素の追加
    pq.push(5);
    pq.push(1);
    pq.push(3);

    // priority_queue::push/pop は O(log n)

    // 要素の取り出し（最大値から）
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl; // 5 3 1

    return 0;
}


// -----------------------------
// 一箇所にまとめた: erase と emplace の実用例
// -----------------------------
// このセクションでは以下をまとめて示す:
//  - シーケンスコンテナ(vector/list) での走査中削除パターン (it = erase(it)) と erase-remove idiom
//  - 連想コンテナ(set/map) での erase(key)/erase(iterator)/erase(range) の使い方
//  - emplace 系の利点 (in-place construction) と try_emplace のメリット
//  - associative container の emplace/insert の戻り値 (pair<iterator,bool>) の活用

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>

// シーケンスコンテナでの削除パターン
void erase_sequence_examples() {
    std::cout << "--- erase: sequence container examples ---\n";

    // vector: 走査しながら条件に合う要素を削除する安全なパターン
    std::vector<int> v = {1,2,3,4,5,6,7};
    for (auto it = v.begin(); it != v.end(); ) {
        // vector::erase(it) は要素の移動が発生するため O(n)（位置に依存）
        if ((*it) % 2 == 1) it = v.erase(it); // erase は次のイテレータを返す
        else ++it;
    }
    std::cout << "vector after erase-while-iterating: ";
    for (int x: v) std::cout << x << " "; // 2 4 6
    std::cout << "\n";

    // list: 連続する値の削除などでも同様に it = erase(it) が使える
    std::list<int> lst = {1,2,2,3,2,4};
    for (auto it = lst.begin(); it != lst.end(); ) {
        // list::erase(it) は双方向連結リストのノード削除で O(1)
        if (*it == 2) it = lst.erase(it);
        else ++it;
    }
    std::cout << "list after erase-while-iterating: ";
    for (int x: lst) std::cout << x << " "; // 1 3 4
    std::cout << "\n";

    // erase-remove idiom: 条件が単純で一括削除できる場合はこれが最も高速
    std::vector<int> v2 = {1,2,3,2,4,2};
    v2.erase(std::remove(v2.begin(), v2.end(), 2), v2.end());
    // erase-remove idiom: std::remove は O(n)、erase は末尾削除で amortized O(1) 相当 -> 全体 O(n)
    std::cout << "vector after erase-remove idiom: ";
    for (int x: v2) std::cout << x << " "; // 1 3 4
    std::cout << "\n\n";
}

// 連想コンテナでの erase の使い方
void erase_associative_examples() {
    std::cout << "--- erase: associative container examples ---\n";

    std::set<int> s = {1,2,3,4,5};
    // キーによる削除: 存在すれば削除して 1 を返す
    // set::erase(key): 要素の検索と削除で O(log n)
    size_t removed = s.erase(3);
    std::cout << "removed count from set: " << removed << "\n";

    // イテレータによる削除
    auto it = s.find(4);
    // set::erase(iterator): ノード削除で一般に amortized O(1)
    if (it != s.end()) s.erase(it);

    // 範囲削除 (例: 2 未満を削除)
    auto first = s.begin();
    auto last = s.lower_bound(2);
    // erase(range): 削除する要素数 k に対して O(k)（ノード単位での削除）
    s.erase(first, last);

    std::cout << "set after erases: ";
    for (int x: s) std::cout << x << " ";
    std::cout << "\n";

    // map の場合: erase(key) は削除した要素数を返す
    std::map<int,std::string> mp = {{1,"a"},{2,"b"},{3,"c"}};
    // map::erase(key): O(log n)
    auto rc = mp.erase(2);
    std::cout << "map removed count for key 2: " << rc << "\n";

    // イテレータによる削除
    auto itmap = mp.find(3);
    // map::erase(iterator): ノード削除で一般に amortized O(1)
    if (itmap != mp.end()) mp.erase(itmap);

    std::cout << "map after erases: ";
    for (auto &kv: mp) std::cout << "("<<kv.first<<","<<kv.second<<") ";
    std::cout << "\n\n";

    // イテレータ更新パターンの例: it = erase(it) を使う（C++11 以降）
    {
        std::cout << "iterator-update erase example (set/map):\n";
        std::set<int> s2 = {1,2,3,4,5,6};
        for (auto it2 = s2.begin(); it2 != s2.end(); ) {
            if ((*it2) % 2 == 0) it2 = s2.erase(it2); // 偶数を削除
            else ++it2;
        }
        std::cout << " set after erase-even: "; for (int x: s2) std::cout << x << " "; std::cout << "\n";

        std::map<int,std::string> mp2 = {{1,"a"},{2,"b"},{3,"c"},{4,"d"}};
        for (auto it2 = mp2.begin(); it2 != mp2.end(); ) {
            if (it2->first % 2 == 0) it2 = mp2.erase(it2); // map::erase(iterator) は次の iterator を返す
            else ++it2;
        }
        std::cout << " map after erase-even-keys: "; for (auto &kv: mp2) std::cout << "("<<kv.first<<","<<kv.second<<") "; std::cout << "\n\n";
    }

    // 注意: map/set の走査中に削除する場合は ++it の順序に注意する（イテレータ無効化に注意）
}

// emplace 系の利点と返り値の使い方をまとめる
void emplace_examples() {
    std::cout << "--- emplace examples ---\n";

    // vector::emplace_back と push_back の違い
    std::vector<std::pair<int,std::string>> vp;
    vp.emplace_back(1, "one"); // in-place construction
    vp.push_back(std::make_pair(2, "two")); // 一時オブジェクトが作られる可能性あり
    std::cout << "vector of pairs: ";
    for (auto &p: vp) std::cout << "("<<p.first<<","<<p.second<<") ";
    std::cout << "\n";

    // map::emplace と try_emplace
    std::map<int,std::string> mp;
    auto r1 = mp.emplace(1, "a");
    if (r1.second) std::cout << "inserted key 1 via emplace\n";

    // try_emplace は既存キーの場合に mapped_type の構築を回避
    mp.try_emplace(2, "b");
    mp.try_emplace(1, "ignored"); // 何もしない
    std::cout << "map contents: ";
    for (auto &kv: mp) std::cout << "("<<kv.first<<","<<kv.second<<") ";
    std::cout << "\n";

    // unordered_map::try_emplace の利点: 無駄な value 構築を避ける
    std::unordered_map<std::string, std::vector<int>> um;
    um.try_emplace("key", 5); // vector(5) を in-place 構築
    // emplace/insert の戻り値 (associative): pair<iterator,bool>
    std::map<int,std::vector<int>> mpv;
    auto res = mpv.emplace(std::piecewise_construct,
                           std::forward_as_tuple(1),
                           std::forward_as_tuple());
    if (res.second) std::cout << "mpv inserted key 1\n";

    // emplace の戻り値を活用する例
    // - .second が true なら挿入成功、false なら既存要素の iterator が返る
    auto [it_ins, ok_ins] = mp.emplace(10, "init");
    if (ok_ins) std::cout << "mp inserted key 10\n";
    else it_ins->second += "_updated";

    // emplace_hint: 挿入位置のヒントを与えて高速化できる場合がある
    auto hintIt = mp.emplace_hint(mp.end(), 20, "hinted");
    std::cout << "emplace_hint inserted key=" << hintIt->first << "\n";

    // try_emplace の実例 (重い構築を避ける)
    std::map<int,std::vector<int>> heavy;
    auto heavy_res = heavy.try_emplace(2, 1000000);
    if (heavy_res.second) std::cout << "constructed heavy value for key 2\n";
    auto heavy_res2 = heavy.try_emplace(2, 1000000);
    if (!heavy_res2.second) std::cout << "did not construct heavy value for key 2 again\n";

    // emplace の返り値から iterator を取り出して要素を参照/更新する例
    // emplace の計算量:
    //  - ordered associative (map/set): O(log n) 比較 + 要素構築コスト
    //  - unordered associative: 平均 O(1) + 要素構築コスト
    auto [it, inserted] = mpv.emplace(3, std::vector<int>{1,2,3});
    if (!inserted) {
        it->second.push_back(99);
    }
    std::cout << "mpv size: " << mpv.size() << "\n\n";
}



