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

в task1 сначала unique забыл после sort потом вспомнил
в task2 accumulate для суммы норм а для произведения вручную пришлось потому что accumulate с 1 нормально но всё равно
в chrono steady_clock взял потому что так правильно
если что компилировал с -Wall -Wextra -O2 как сказали
