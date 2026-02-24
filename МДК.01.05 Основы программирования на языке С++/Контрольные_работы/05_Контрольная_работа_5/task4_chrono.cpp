task4.cpp — chrono время цикла
#include <iostream>
#include <chrono>

int main() {
    using namespace std::chrono;
    
    auto start = steady_clock::now();
    
    long long sum = 0;
    for(int i = 0; i < 10000000; i++) {
        sum += i;
    }
    
    auto end = steady_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();
    std::cout << "первый цикл: " << ms << " мс\n";
    
    // второй цикл
    start = steady_clock::now();
    
    sum = 0;
    for(int i = 0; i < 10000000; i++) {
        sum += i * i;
    }
    
    end = steady_clock::now();
    ms = duration_cast<milliseconds>(end - start).count();
    std::cout << "второй цикл (квадраты): " << ms << " мс\n";
    
    return 0;
}
