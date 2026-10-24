#include "CStr.h"
#include <cstring>
#include <cstdlib>
#include <ctime>
 
 
char* CStr::generateRandomString(int len) {
    if (len < 0) len = 0;
    if (len > 20) len = 20;

    char* res = new char[len + 1];
    for (int i = 0; i < len; i++) {
        res[i] = 'a' + rand() % 26;
    }
    res[len] = '\0';
    return res;
}

 CStr::CStr() {
    int len = rand() % 20 + 1;
    str = generateRandomString(len);
}

 
CStr::CStr(const char* s) {
    if (s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else {
        str = new char[1];
        str[0] = '\0';
    }
}

 
CStr::CStr(int len) {
    str = generateRandomString(len);
}
 CStr::CStr(const CStr& other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}
 CStr::~CStr() {
    delete[] str;
}

 
CStr& CStr::operator=(const CStr& other) {
    if (this != &other) {
        delete[] str;
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
    return *this;
}

 
CStr& CStr::operator=(const char* s) {
    delete[] str;
    if (s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else {
        str = new char[1];
        str[0] = '\0';
    }
    return *this;
}

 bool CStr::operator>(const CStr& other) {
    return strcmp(str, other.str) > 0;
}
 
 
CStr CStr::operator+(const CStr& other) {
    CStr result;
    delete[] result.str;

    result.str = new char[strlen(str) + strlen(other.str) + 1];
    strcpy(result.str, str);
    strcat(result.str, other.str);
    return result;
}

 
CStr& CStr::operator+=(const CStr& other) {
    char* t = new char[strlen(str) + strlen(other.str) + 1];
    strcpy(t, str);
    strcat(t, other.str);

    delete[] str;
    str = t;
    return *this;
}

 
char& CStr::operator[](int index) {
    return str[index];
}

 
int CStr::length() {
    return strlen(str);
}

 ostream& operator<<(ostream& os, const CStr& s) {
    os << s.str;
    return os;
}

 
istream& operator>>(istream& is, CStr& s) {
    char buffer[256];
    is >> buffer;
    s = buffer;
    return is;
}