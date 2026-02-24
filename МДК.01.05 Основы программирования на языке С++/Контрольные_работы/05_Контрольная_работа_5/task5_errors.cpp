task5.cpp — ввод числа исключения

#include <iostream>
#include <stdexcept>

int main() {
    std::cout << "введи число: ";
    
    int num;
    if(!(std::cin >> num)) {
        std::cout << "это не число!\n";
        return 1;
    }
    
    try {
        if(num < 0) {
            throw std::runtime_error("отрицательное число запрещено");
        }
        std::cout << "норм число: " << num << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "ошибка: " << e.what() << std::endl;
    }
    
    return 0;
}
