// 配列の操作
#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    // 配列の要素にアクセス
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
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

    // 要素へのアクセス
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl; // 1 2 3 4 5 6


    // 3行5列の二次元ベクトルを全て0で初期化
    int rows = 3;
    int cols = 5;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

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

    // 末尾の要素を削除
    vec.pop_back();

    // ベクトルが空かどうかを確認
    if (vec.empty()) {
        std::cout << "Vector is empty" << std::endl;
    }

    // 3以上の最小の要素(ソート済みでないと正しい結果は得られない)
    auto it = lower_bound(vec.begin(), vec.end(), 3);
    // 距離(index)を求める
    std::cout << distance(vec.begin(),it) << std::endl;

    // 3番目の位置に10を挿入
    vec.insert(vec.begin() + 2, 10);

    // 3番目の要素を削除 (インデックスは2)
    vec.erase(vec.begin() + 2);

    // 値が2の要素を全て削除
    vec.erase(std::remove(vec.begin(), vec.end(), 2), vec.end());

    // 2番目から4番目の要素を削除 (インデックスは1から3)
    vec.erase(vec.begin() + 1, vec.begin() + 4);

	// 配列の重複を消す
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

    // 全ての要素を削除
    vec.clear();

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
    if (it != vec.end()) {
        std::cout << "Found 3 at position " << std::distance(vec.begin(), it) << std::endl;
    }

    // 逆順
    std::reverse(vec.begin(), vec.end());
    for (int i : vec) {
        std::cout << i << " "; // 5 4 3 2 1
    }
    std::cout << std::endl;

    // 合計
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    long long sumLL = std::accumulate(vec.begin(), vec.end(), 0LL);
    std::cout << "Sum: " << sum << std::endl; // Sum: 15

    // 最大値
    int maxElement = *std::max_element(vec.begin(), vec.end());
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
    std::cout << std::endl; // 1 2 3

    return 0;
}



// 優先度付きキュー
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> pq;

    // デフォルトと同じ
    priority_queue<int, vector<int>, less<int>> T;
    // これを使うと逆順
    priority_queue<int, vector<int>, greater<int>> T;

    // 要素の追加
    pq.push(5);
    pq.push(1);
    pq.push(3);

    // 要素の取り出し（最大値から）
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl; // 5 3 1

    return 0;
}