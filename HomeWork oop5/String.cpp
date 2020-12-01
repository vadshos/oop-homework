#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <cstring>


using  std::cout;
using  std::endl;

String::String() : Str(0), Length(0)
{
}



String& String::concat(const String& obj)
{
	String temp;
	temp = *this;
	temp += obj;
	return *this;
}

String& String::methot(const String& obj)
{
	int count = 0;
	int j = 0;
	for (size_t i = 0; i < Length; i++) {
		for (size_t j = 0; j < obj.Length; j++) {
			if (Str[i] == obj.Str[j]) {
				cout << Str[i];
			}
		}
	}
	return *this;
}

String& String::operator+=(const String& obj)
{
	size_t lenght = strlen(this->Str) + strlen(obj.Str);
	char* str = new char[lenght + 1];

	for (int i = 0; i < strlen(this->Str); i++) {
		str[i] = this->Str[i];
	}
	for (int i = strlen(this->Str), j = 0; i <= lenght; i++, j++) {
		str[i] = obj.Str[j];
	}

	delete this->Str;
	this->Str = str;

	return *this;
}

String& String::operator++()
{

	int*  temp = new int[Length];
	for (int i = 0; i < Length; i++) {
		temp[i] = char(Str[i]);
		temp[i] = temp[i]++;
		Str[i] = char(temp[i]);
	}
	return *this;
	
}

String& String::operator++(int)
{
	String temp = *this;
	++* this;
	return temp;
}

String& String::operator*(const String& obj){
	for (size_t i = 0; i < Length; i++) {
		for (size_t j = 0; j < obj.Length; j++) {
			if (Str[i] == obj.Str[j]) {
				cout << Str[i];
			}
		}
	}
	return *this;
}

String& String::operator=(String& obj)
{
	if (this != &obj)
	{
		delete[] this->Str;
		Length = strlen(obj.Str);
		this->Str = new char[Length + 1];
		strcpy_s(Str, Length+1,obj.Str);
	}

	return *this;
}

String& String::operator!()
{
	char* ch = new char[Length];
	ch = { Str };
	for (size_t i = 0; i < (sizeof ch)/2; i++) {
		swap(ch[i], ch[((sizeof ch) - 1) - i]);
	}
	String temp(ch);
	return *this;
}
String String::operator()(size_t firstIndex, size_t lastIndex ) const
{
	if (firstIndex < this->Length) {
		String Str2(lastIndex);
		if (lastIndex < this->Length && lastIndex > firstIndex) {
			for (size_t i = 0, j = firstIndex; i < lastIndex; i++, j++) {
				Str2[i] = Str[j];
			}
			return Str2;
		}
	}
	lastIndex = 0;
	String Str2(lastIndex);
	return Str2;

}

String String::operator()(size_t firstIndex) const
{
	size_t lastIndex = Length-1;
	if (firstIndex < this->Length) {
		String Str2(lastIndex);
		if (lastIndex < this->Length && lastIndex > firstIndex) {
			for (size_t i = 0, j = firstIndex; i < lastIndex; i++, j++) {
				Str2[i] = Str[j];
			}
			return Str2;
		}
	}
	lastIndex = 0;
	String Str2(lastIndex);
	return Str2;
}

String::~String()
{

	Length = 0;
	delete[] Str;
	Str = nullptr;
}


String::String(const char* ptr)  : Length (strlen(ptr)) , Str(new char[strlen(ptr)+1])
{
	strcpy_s(Str, Length+1, ptr);
}
String::String(const size_t l) : Length(l), Str(new char[l + 1])
{
}
String::String(const String& t) 
{
	Length = (strlen(t.Str));
	Str = (new char[strlen(t.Str) + 1]);
	strcpy(Str, t.Str);
}
char& String::operator[](size_t index)
{
	static char DUMMY;
	DUMMY = '\0';
	//std::cerr << "Index out of range. \n";
	return (index >= 0 && index < strlen(this->Str)) ? this->Str[index] : DUMMY;
}

ostream& String::show(ostream& os) const
{
	return os << "\"" << (Str ? Str : "") << "\"";
}
bool String::operator==(const String& obj)
{

	return !strcmp(this->Str, obj.Str);
}

bool String::operator!=(const String& obj)
{
	return (strcmp(this->Str, obj.Str));
}

bool String::operator>(const String& obj)
{
	return (strlen(this->Str) > strlen(obj.Str)) ? true : false;
}

bool String::operator>=(const String& obj)
{
	return (strlen(this->Str) >= strlen(obj.Str)) ? true : false;
}

bool String::operator<(const String& obj)
{
	return (strlen(this->Str) < strlen(obj.Str)) ? true : false;
}

bool String::operator<=(const String& obj)
{
	return (strlen(this->Str) <= strlen(obj.Str)) ? true : false;
}