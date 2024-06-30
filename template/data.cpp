#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    // 配列の要素にアクセス
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}



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
    std::cout << std::endl;

    return 0;
}



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
    std::cout << std::endl;

    return 0;
}



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

    return 0;
}



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



#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> pq;

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



// #include <iostream>
// #include <algorithm>
// #include <vector>

// int main() {
//     std::vector<int> vec = {1, 2, 3, 4, 5};

//     // 逆順
//     std::reverse(vec.begin(), vec.end());
//     for (int i : vec) {
//         std::cout << i << " "; // 5 4 3 2 1
//     }
//     std::cout << std::endl;

//     // 合計
//     int sum = std::accumulate(vec.begin(), vec.end(), 0);
//     std::cout << "Sum: " << sum << std::endl; // Sum: 15

//     // 最大値
//     int maxElement = *std::max_element(vec.begin(), vec.end());
//     std::cout << "Max element: " << maxElement << std::endl; // Max element: 5

//     return 0;
// }
