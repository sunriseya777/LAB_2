#define _CRT_SECURE_NO_WARNINGS
#include "CStrArray.h"

// 1. Конструктор
CStrArray::CStrArray(int cap) {
    if (cap <= 0) cap = 1;
    capacity = cap;
    size = 0;
    arr = new CStr * [capacity]; // Создаем массив указателей

    // Инициализируем нулями (nullptr)
    for (int i = 0; i < capacity; i++) {
        arr[i] = nullptr;
    }
}

// 3. Деструктор
CStrArray::~CStrArray() {
    // ВАЖНО: Мы удаляем только массив указателей!
    // Сами объекты CStr удаляются там, где были созданы (в main).
    delete[] arr;
}

// 2. Добавление элемента
CStrArray& CStrArray::operator+=(CStr* ptr) {
    if (size >= capacity) {
        // Если места нет, расширяем массив (увеличиваем в 2 раза)
        capacity *= 2;
        CStr** newArr = new CStr * [capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    arr[size++] = ptr;
    return *this;
}

// 4. Оператор индексации (возвращает указатель)
CStr* CStrArray::operator[](int index) const {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс за пределами массива!" << endl;
        return nullptr;
    }
    return arr[index];
}

// 5. Сортировка по содержанию (метод "пузырька")
void CStrArray::SortByContent() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Используем перегруженный оператор > из класса CStr
            if (*arr[j] > *arr[j + 1]) {
                // Меняем местами УКАЗАТЕЛИ, а не сами объекты
                CStr* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 6. Сортировка по длине
void CStrArray::SortByLength() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Сравниваем длины строк
            if (arr[j]->length() > arr[j + 1]->length()) {
                CStr* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 7. Проверка на упорядоченность по содержанию
bool CStrArray::IsSortedByContent() const {
    for (int i = 0; i < size - 1; i++) {
        // Если текущий больше следующего, значит массив НЕ отсортирован
        if (*arr[i] > *arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// 8. Вывод в поток
ostream& operator<<(ostream& os, const CStrArray& ca) {
    if (ca.size == 0) {
        os << "[Empty array]";
        return os;
    }
    for (int i = 0; i < ca.size; i++) {
        if (ca.arr[i] != nullptr) {
            // Выводим только саму строку. Никакого "длина:" на русском!
            os << *ca.arr[i] << "\n";
        }
    }
    return os;

}