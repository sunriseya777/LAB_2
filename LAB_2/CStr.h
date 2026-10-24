#pragma once

#include <iostream>

using namespace std;

class CStr {
private:
    char* str;

     
    static char* generateRandomString(int len);

public:
    CStr();                              
    CStr(const char* s);                 
    CStr(int len);                       
    CStr(const CStr& other);             
    ~CStr();                             

    CStr& operator=(const CStr& other); 
    CStr& operator=(const char* s);     

    bool operator>(const CStr& other);  

    CStr operator+(const CStr& other);  
    CStr& operator+=(const CStr& other);  

    char& operator[](int index);        
    int length();                       
    friend ostream& operator<<(ostream& os, const CStr& s);
    friend istream& operator>>(istream& is, CStr& s);
};