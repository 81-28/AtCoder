#include <iostream>
#include <string>

int main() {
    // 文字列の初期化
    std::string str1 = "Hello, World!";
    std::string str2("Hello, AtCoder!");

    // 出力例
    std::cout << str1 << std::endl; // Hello, World!
    std::cout << str2 << std::endl; // Hello, AtCoder!
    
    return 0;
}



#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello, ";
    std::string str2 = "World!";
    std::string str3 = str1 + str2;

    // 出力例
    std::cout << str3 << std::endl; // Hello, World!
    
    return 0;
}



#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // 文字列の長さを取得
    size_t length = str.length();

    // 出力例
    std::cout << "Length: " << length << std::endl; // Length: 13
    
    return 0;
}



#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // 部分文字列を取得
    std::string substr = str.substr(7, 5); // "World"

    // 出力例
    std::cout << "Substring: " << substr << std::endl; // Substring: World
    
    return 0;
}



#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // 文字列の検索
    size_t pos = str.find("World");

    // 出力例
    if (pos != std::string::npos) {
        std::cout << "'World' found at position: " << pos << std::endl; // 'World' found at position: 7
    } else {
        std::cout << "'World' not found" << std::endl;
    }
    
    return 0;
}


#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string str = "This is a test string. This string is for testing.";
    std::string target = "is";
    std::vector<size_t> positions;
    size_t pos = str.find(target);

    // target文字列が見つかる限りループ
    while (pos != std::string::npos) {
        positions.push_back(pos);
        pos = str.find(target, pos + 1);
    }

    // 結果を出力
    if (positions.empty()) {
        std::cout << "The substring \"" << target << "\" was not found in the string." << std::endl;
    } else {
        std::cout << "The substring \"" << target << "\" was found at positions: ";
        for (size_t p : positions) {
            std::cout << p << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}




#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // 文字列の置換
    str.replace(7, 5, "AtCoder");

    // 出力例
    std::cout << str << std::endl; // Hello, AtCoder!
    
    return 0;
}



#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string str = "Hello, World! This is AtCoder.";
    std::istringstream iss(str);
    std::string word;
    std::vector<std::string> words;

    // 文字列の分割
    while (iss >> word) {
        words.push_back(word);
    }

    // 出力例
    for (const auto& w : words) {
        std::cout << w << std::endl;
    }
    // Hello,
    // World!
    // This
    // is
    // AtCoder.

    return 0;
}
