#pragma once

#include <iostream>
#include "CStr.h" // Подключаем наш класс строки

using namespace std;

class CStrArray {
private:
    CStr** arr;      // Динамический массив указателей на CStr
    int capacity;    // Выделено памяти (вместимость)
    int size;        // Реальное количество элементов

public:
    // 1. Конструктор с параметрами «длина массива»
    CStrArray(int cap = 10);

    // 3. Деструктор
    ~CStrArray();

    // 2. Оператор += для добавления одного элемента (указателя)
    CStrArray& operator+=(CStr* ptr);

    // 4. Оператор индексации [] (возвращает указатель на объект CStr)
    CStr* operator[](int index) const;

    // 5. Косвенная сортировка по содержанию строк
    void SortByContent();

    // 6. Косвенная сортировка по длине строк
    void SortByLength();

    // 7. Проверка упорядоченности массива по содержанию строк
    bool IsSortedByContent() const;

    // 8. Оператор вывода в поток <<
    friend ostream& operator<<(ostream& os, const CStrArray& ca);
};