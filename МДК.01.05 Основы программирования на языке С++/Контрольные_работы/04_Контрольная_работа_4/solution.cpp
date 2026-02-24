Контрольная 4
  Часть А теория

struct в плюсах это как тип данных который сам придумал, состоит из разных полей
как класс но по умолчанию всё public
данные внутри структуры хранятся подряд в памяти в том порядке как написаны поля
между полями может быть выравнивание (padding) чтобы быстрее работало на процессоре
композиция это когда одна структура содержит внутри другую структуру как поле
нужно чтобы удобно группировать данные например в структуре Человек есть поле Адрес который сам struct
удобно потому что логика вместе и можно передавать копировать легко
enum это перечисление набор именованных констант типа
enum Color {RED, GREEN, BLUE};
потом можно Color c = RED;
typedef и using почти одно и тоже но using лучше
typedef int* ptr;
using ptr = int*;
using можно с шаблонами typedef нет
using выглядит современнее и понятнее
да можно struct с массивами и vector
в структуре можно поле int arr[10]; или std::vector<int> grades;
и наоборот можно vector<Student> students; или Student group[30];

Часть Б практика

структура Student и функции

#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age;
    double avgGrade;
};

void printStudent(const Student& s) {
    std::cout << "Имя: " << s.name << " возраст: " << s.age 
              << " средний балл: " << s.avgGrade << std::endl;
}

bool isOtlichnik(const Student& s) {
    return s.avgGrade >= 4.5;   // типа 4.5 и выше человек без личной жизни
}

enum DayOfWeek и проверка выходной

   enum DayOfWeek {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

bool isWeekend(DayOfWeek day) {
    return day == SATURDAY || day == SUNDAY;
}

структура Book + vector<Book>

    struct Book {
    std::string title;
    std::string author;
    int year;
};

int main() {
    std::vector<Book> library;
    
    library.push_back({"Война и мир", "Толстой", 1869});
    library.push_back({"Меч Предназначения", "Сапковский", 1992});
    library.push_back({"Сантехник, его кот, жена и другие подробности", "СлаваСэ", 2008});
    library.push_back({"Грокаем алгоритмы", "Бхаргава", 2016});
    library.push_back({"Некронамикон", "Лафкрафт", 1938});
    
    std::cout << "Все книги:\n";
    for(const auto& b : library) {
        std::cout << b.title << " - " << b.author << " (" << b.year << ")\n";
    }
    
    std::cout << "\nКниги после 2015:\n";
    for(const auto& b : library) {
        if(b.year > 2015) {
            std::cout << b.title << " - " << b.author << " (" << b.year << ")\n";
        }
    }
    
    // тест студента
    Student vasya {"Ваня", 20, 4.8};
    printStudent(vasya);
    if(isOtlichnik(vasya)) std::cout << "Отличник!\n";
    
    // тест дня защитника Отечества
    if(isWeekend(SUNDAY)) std::cout << "выходной\n";
    
    return 0;
}
