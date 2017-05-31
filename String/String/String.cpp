// String.cpp
#include <iostream>
using namespace std;

#include "String.h"


/* Konstruktor - leer */
String::String() {
	size = 0;
	str = new char[1];
	str[0] = '\0';
}


/* Konstruktor mit einzelnen Char */
String::String(char c) {
	size = 0;
	str = new char[2];
	str[0] = c;
	str[1] = '\0';
}


/* Konstruktor mit Char-Folge */ 
String::String(const char *s) {
	if (s)
	{
		int x = 0;
		while (s[x] != '\0') {
			x++;
		}
		size = x;
		str = new char[x + 1];
		for (int i = 0; i < x; i++) {
			str[i] = s[i];
		}
		str[size] = '\0';
	}
	else
	{
		size = 0;
		str = new char[1];
		str[0] = '\0';
	}

}


/* Konstruktor mit String-Kopie über Parameter */
String::String(const String& s) {
	str = new char[s.size + 1];
	size = s.size;

	for (int i = 0; i < s.size; i++) {
		str[i] = s.str[i];
	}
	str[s.size] = '\0';
}


String::~String() {
	delete[] str;
}


char& String::operator[](int index) {
	return str[index];
}


String& String::operator=(String& s) {
	if (this == &s) return *this;

	delete str;
	str = new char[s.size + 1];
	size = s.size;

	for (int i = 0; i < s.size; i++)
		str[i] = s.str[i];
	str[size] = '\0';
	return *this;
}


String& String::operator+=(String& s) {
	if (size != 0) 
	{
		int len = size + s.size;
		char* newStr = new char[len+1];

		for (int i = 0; i < size; i++)
			newStr[i] = str[i];

		for (int i = 0; i < s.size; i++)
			newStr[size + i] = s.str[i];
		delete str;
		size = len;
		str = newStr;
		str[len] = '\0';
		return *this;
	}
	else 
	{
		String::operator=(s);
	}
}