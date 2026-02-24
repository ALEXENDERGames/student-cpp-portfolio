Контрольная работа №3
Часть А теория
ссылка и указатель разница
ссылка типа alias на переменную нельзя nullptr нельзя поменять куда смотрит синтаксис без звездочек
указатель это адрес может быть null можно менять можно ++ -- арифметика

ссылку юзаю когда передаю в функцию и не хочу копировать и точно есть объект
указатель когда может быть ничего (nullptr) или массив или new delete или хочу сам указатель поменять

если *nullptr то segmentation fault или undefined обычно программа падает краш
возвращать ссылку на локальную переменную ни в коем случае нельзя
локалка умирает после } функции ссылка остаётся на мусор потом обращаешься — краш или мусорные значения
new память в куче берёт возвращает указатель
delete освобождает
delete[] для массивов потому что надо деструкторы всем вызвать и блок целиком освободить
висячий указатель это когда указатель показывает туда где уже delete или объект умер
как избежать после delete сразу ptr = nullptr;
не возвращать &локальной переменной
не хранить указатели на временные штуки
указатель на функцию это переменная которая держит адрес функции
пример

int (*ptr)(int a, int b);
потом ptr = какаятоФункция;
ptr(5,6);
Часть Б практика

функция +10 по ссылке

void addTen(int& x) {
x = x + 10;
}

указатель на максимум в массиве

int* getMax(int* mas, int razmer) {
if(razmer <= 0) return nullptr;
int* maxPtr = mas;
for(int i=1; i<razmer; i++){
if(mas[i] > *maxPtr) maxPtr = &mas[i];
}
return maxPtr;
}

createArray от 1 до n

int* createArray(int n){
int* p = new int[n];
for(int i=0; i<n; i++){
p[i] = i+1;
}
return p;
}

двумерный массив n*m указатели рандом

в main типа
int n,m;
cin>>n>>m;
int** mat = new int*[n];
for(int i=0;i<n;i++){
mat[i] = new int[m];
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
mat[i][j] = rand()%100;
}
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
cout << mat[i][j] << " ";
}
cout<<endl;
}
// чистим
for(int i=0;i<n;i++) delete[] mat[i];
delete[] mat;

processString C-строка

void processString(char* str){
if(str == nullptr) return;
while(*str != '\0'){
if(*str >= 'a' && *str <= 'z'){
*str = *str - 'a' + 'A';
}
else if(*str >= '0' && *str <= '9'){
str = '';
}
else if(*str == ' '){
*str = '_';
}
str = str + 1;
}
}
Часть С программа
#include <iostream>
using namespace std;
void minMax(int* arr, int n, int& mn, int& mx){
if(n==0){ mn=mx=0; return;}
mn = mx = arr[0];
for(int i=1;i<n;i++){
if(arr[i]<mn) mn=arr[i];
if(arr[i]>mx) mx=arr[i];
}
}
void doubleIt(int* arr, int n){
for(int i=0;i<n;i++) arr[i]*=2;
}
int main(){
int n;
cout<<"размер "; cin>>n;
if(n<=0){ cout<<"дуракнеумный\n"; return 1;}
int* mas = new int[n];
cout<<"вводи "<<n<<" чисел\n";
for(int i=0;i<n;i++) cin>>mas[i];
cout<<"было: ";
for(int i=0;i<n;i++) cout<<mas[i]<<" "; cout<<endl;
int mini,maxi;
minMax(mas,n,mini,maxi);
cout<<"мин "<<mini<<" макс "<<maxi<<endl;
void (func)(int,int) = doubleIt;
func(mas,n);
cout<<"стало: ";
for(int i=0;i<n;i++) cout<<mas[i]<<" "; cout<<endl;
delete[] mas;
return 0;
}
