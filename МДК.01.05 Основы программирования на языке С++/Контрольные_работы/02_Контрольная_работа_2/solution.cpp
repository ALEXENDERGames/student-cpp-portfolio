Контрольная №2
Часть А
Функция в плюсах это кусок кода который можно много раз вызывать по имени и он что-то делает может принимать параметры и может что-то возвращать
Прототип это когда пишешь объявление функции без тела типа
int sum(int a, int b);
нужно чтобы компилятор знал что такая функция вообще есть когда ты её вызываешь раньше чем она описана в коде
Передача по значению это когда в функцию копируется значение аргумента
меняешь внутри функции — снаружи ничего не меняется
типа void f(int x) { x = 100; } — оригинал не затронуло
По ссылке это когда передаётся не копия а сама переменная
внутри функции пишешь int& x и любое изменение внутри сразу видно снаружи
void f(int& x) { x = 100; } — оригинал станет 100
Рекурсия это когда функция вызывает сама себя
обязательно должно быть условие выхода (базовый случай) иначе будет бесконечный цикл и стек переполнится
inline это подсказка компилятору чтобы он вместо вызова функции просто вставил её код в то место где вызывается
используют для маленьких функций которые часто вызываются чтобы не тратить время на вызов
Макрос это когда через #define пишешь типа
#define PI 3.14
или #define SQR(x) ((x)*(x))
он просто текстовая замена до компиляции ничего не знает про типы и синтаксис
Макросы опасные потому что это тупо замена текста
может получиться фигня типа если написать SQR(a++) то будет ((a++)*(a++)) и переменная увеличится два раза
плюс нет проверки типов и скобки иногда забывают — из-за этого куча багов
Шаблон функции это когда пишешь функцию которая работает с любым типом
типа template <typename T> T max(T a, T b) { return a > b ? a : b; }
чтобы не писать одну и ту же функцию для int float double и тд
Когда компилятор видит вызов шаблонной функции с конкретным типом он создаёт (инстанцирует) обычную функцию уже с этим типом
например max<int> или max<double> — компилятор сам генерит нужные версии кода

#include <iostream>
#include <string>
Часть Б
  
int countUpper(const string& s) {   // лучше с const но я забыл сначала
    int cnt = 0;
    for(char c : s) {
        if(c >= 'A' && c <= 'Z') cnt++;
    }
    return cnt;
}

int countDigits(string s) {   // тут без const случайно
    int kol = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='0' && s[i]<='9') kol++;
    }
    return kol;
}

void replaceExclamation(string& str) {
    for(char& c : str) {     // & чтобы менять
        if(c == '!') c = '.';
    }
}

int main() {
    string text = "Hello! World 2025!!! ABC 123";
    
    std::cout << "Заглавных букв: " << countUpper(text) << "\n";
    std::cout << "Цифр: " << countDigits(text) << "\n";
    
    replaceExclamation(text);
    std::cout << "После замены: " << text << "\n";
    
    // должно быть примерно: Заглавных 6, Цифр 4, После: Hello. World 2025...
}

Рекурсивная функция переворота строки (без циклов)

C++void reverseString(string& s, int start = 0) {
    int end = s.length() - 1 - start;
    
    if(start >= end) return;   // базовый случай
    
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    
    reverseString(s, start+1);   // рекурсия
}

// или другой вариант 
string reverseRecursive(string s) {
    if(s.length() <= 1) return s;
    
    return reverseRecursive(s.substr(1)) + s[0];
}

// но в задании по ссылке поэтому первый вариант лучше
в main можно так проверить:
C++string word = "abcdef";
reverseString(word);
cout << word << endl;   // должно быть fedcba

Шаблонная inline-функция sumElements

C++#include <vector>
#include <array>

template<typename T>
inline T sumElements(const std::vector<T>& v) {
    T sum = 0;   // или T{}  не уверен
    for(int i=0; i<v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

template<typename T, size_t N>
inline T sumElements(const std::array<T, N>& arr) {
    T suma = 0;
    for(int i=0; i<N; i++) {
        suma = suma + arr[i];
    }
    return suma;
}

// можно было бы сделать одну через range-based for
// но в задании написано "в обычном цикле for" поэтому так
// тест
int main() {
    std::vector<int> vec{1,2,3,4,5};
    std::array<double, 4> ar{1.5, 2.5, 3.5, 4.5};
    
    cout << sumElements(vec) << "\n";      // 15
    cout << sumElements(ar) << "\n";       // 12
}
