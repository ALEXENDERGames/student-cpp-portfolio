task2.cpp — вектор accumulate и прочее
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<int> v = {3,7,1,9,4,2,8,5,6,0};
    
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "сумма = " << sum << std::endl;
    
    long long prod = 1;
    for(int x : v) prod *= x;
    std::cout << "произведение = " << prod << std::endl;
    
    auto [minIt, maxIt] = std::minmax_element(v.begin(), v.end());
    std::cout << "разница max-min = " << *maxIt - *minIt << std::endl;
    
    return 0;
}
