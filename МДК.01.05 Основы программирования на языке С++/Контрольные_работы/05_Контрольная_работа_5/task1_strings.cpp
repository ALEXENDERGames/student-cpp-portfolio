task1.cpp — строка разбить удалить дубликаты отсортировать
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    std::string s = "apple,banana,orange,apple,kiwi";
    
    std::vector<std::string> words;
    std::stringstream ss(s);
    std::string word;
    
    while(std::getline(ss, word, ',')) {
        words.push_back(word);
    }
    
    // удалить дубликаты
    std::sort(words.begin(), words.end());
    auto it = std::unique(words.begin(), words.end());
    words.erase(it, words.end());
    
    std::cout << "Результат: ";
    for(const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
