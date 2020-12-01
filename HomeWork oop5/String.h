#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char* Str;
    size_t Length;
public:
    String();
    String(const char* ptr);
    String(const size_t Length);
    String(const String& temp);
    char& operator[](size_t index);
    void setStr(const char* ptr);
    String& concat(const String& obj);
    String& methot(const String& obj);
    String& operator++();
    String& operator++(int);
    String& operator*(const String& obj);
    String& operator = (String& obj);
    String& operator!();
    String& operator+=(const String& obj);
    String operator()(size_t firstIndex, size_t lastIndex ) const;
    String operator()(size_t firstIndex) const;
    bool operator== (const String& obj);
    bool operator!=(const String& obj);
    bool operator>(const String& obj);
    bool operator>=(const String& obj);
    bool operator<(const String& obj);
    bool operator<=(const String& obj);
    ostream& show(ostream& os) const;
    friend istream& operator >> (istream& os, const String& s);
    friend ostream& operator << (ostream& os, const String& Str);
    friend String operator+(const String& objFirst, const String& objSecond);
    ~String();
};
inline  ostream& operator << (ostream& os, const String& Str) {
    return Str.show(os);
}
inline void String::setStr(const char* ptr) {
    Length = (strlen(ptr));
    Str = (new char[strlen(ptr) + 1]);
    strcpy_s(Str, Length + 1, ptr);
}
inline String operator+(const String& objFirst, const String& objSecond)
{
    String temp = objFirst;

    return temp += objSecond;
}
inline istream& operator>>(istream& is, String& obj)
{
    char BUFF[2048];
    is.getline(BUFF, sizeof BUFF);
    obj.setStr(BUFF);
    return is;
}
