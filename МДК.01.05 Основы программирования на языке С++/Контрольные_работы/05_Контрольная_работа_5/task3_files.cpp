task3.cpp — файл numbers.txt
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

int main() {
    // запись
    std::ofstream out("numbers.txt");
    if(!out) {
        std::cout << "не могу создать файл\n";
        return 1;
    }
    out << "10 20 30 40 50\n";
    out.close();
    
    // чтение
    std::ifstream in("numbers.txt");
    std::vector<int> nums;
    int x;
    while(in >> x) {
        nums.push_back(x);
    }
    in.close();
    
    if(nums.empty()) {
        std::cout << "пусто\n";
        return 1;
    }
    
    double avg = std::accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
    std::cout << "среднее = " << avg << std::endl;
    
    return 0;
}
