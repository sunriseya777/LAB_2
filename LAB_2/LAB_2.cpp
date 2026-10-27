#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "CStr.h"
#include "CStrArray.h"

using namespace std;

int main()
{
    srand(time(0));
    cout << "class CStr\n\n";

    CStr s1;
    cout << "s1(rand): " << s1 << ", length: " << s1.length() << "\n";

    CStr s2("allo");
    cout << s2 << "\n";

    CStr s3(5);
    cout << s3 << "\n";

    CStr s4(s2);
    cout << s4 << "\n";

    CStr s5;
    s5 = s2;
    cout << s5 << "\n";
    s5 = "World";
    cout << s5 << "\n";

    CStr s6 = s1 + CStr(" .");
    cout << s6 << "\n";

    s6 += CStr("><");
    cout << s6 << "\n";

    cout << "s6>s5? " << (s6 > s5 ? "yes" : "no") << "\n";

    s5[0] = 'B';
    cout << "s5[0] = 'B':  " << s5 << "\n\n";

    cout << "s7? : ";
    CStr s7;
    cin >> s7;
    cout << "s7  : " << s7 << ", len: " << s7.length()<<"\n";
    cout << "-------------------------------------------------------\n";
    
    // 1. Создаем контейнер заданной длины
    CStrArray container(5);

    // 2. Создаем объекты CStr
    CStr c1("Banana");
    CStr c2("Apple");
    CStr c3("Cherry");
    CStr c4("Dog");
    CStr c5("Elephant");

    // 3. Добавляем их в массив
    container += &c1;
    container += &c2;
    container += &c3;
    container += &c4;
    container += &c5;

    cout << "=== Initial array ===" << endl;
    cout << container << endl;

    // 4. Проверяем сортировку
    cout << "Is sorted by content? "
        << (container.IsSortedByContent() ? "Yes" : "No") << "\n\n";

    // 5. Сортируем по содержанию
    container.SortByContent();
    cout << "=== After sorting by content ===" << endl;
    cout << container << endl;

    cout << "Is sorted by content? "
        << (container.IsSortedByContent() ? "Yes" : "No") << "\n\n";

    // 6. Сортируем по длине
    container.SortByLength();
    cout << "=== After sorting by length ===" << endl;
    cout << container << endl;

    // 7. Проверяем оператор индексации
    cout << "\nElement at index 0: " << *container[0] << endl;

    return 0;



        
}

 