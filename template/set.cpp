#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet = {10, 20, 30, 40, 50}; // setの宣言と初期化

    mySet.insert(60); // 要素の追加
    mySet.erase(20); // 要素の削除

    auto it = mySet.find(30); // 要素の検索
    if (it != mySet.end()) cout << "30が見つかりました。" << endl;

    if (mySet.count(50) > 0) cout << "50はセットに含まれています。" << endl; // 要素の存在チェック

    cout << "最小値: " << *mySet.begin() << endl; // 最小値の取得
    cout << "最大値: " << *mySet.rbegin() << endl; // 最大値の取得

    auto it_lower = mySet.lower_bound(35); // 35以上の最小の要素
    if (it_lower != mySet.end()) cout << "35以上の最小の要素: " << *it_lower << endl;

    auto it_upper = mySet.upper_bound(30); // 30より大きい最初の要素
    if (it_upper != mySet.end()) cout << "30より大きい最初の要素: " << *it_upper << endl;

    cout << "要素数: " << mySet.size() << endl; // 要素数の取得
    if (mySet.empty()) cout << "セットは空です。" << endl; // 空の確認

    for (const auto &element : mySet) cout << element << " "; // 全要素の出力
    cout << endl;
    
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    set<int> anotherSet = {1, 2, 3};
    anotherSet.swap(mySet); // 要素の交換

    mySet.clear(); // 全要素のクリア
    cout << "クリア後の要素数: " << mySet.size() << endl;

    return 0;
}
