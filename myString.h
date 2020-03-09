#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#include <iostream>
using namespace std;

class myString{
    private:
        int space = 0;
        char* p;

    public:
        myString();
        myString(const char*); //ctor
        myString(const myString&); //copy ctor
        ~myString(); //dtor

        myString operator+(const char*);
        myString operator+(const myString&);
        myString operator+=(const char*);
        myString operator+=(const myString&);
        myString& operator=(const char*);
        myString& operator=(const myString&);

        bool operator>(const myString&);
        bool operator<(const myString&);
        bool operator>=(const myString&);
        bool operator<=(const myString&);
        bool operator==(const myString&);
        bool operator!=(const myString&);

        char operator[](int index);

        myString substr(int, int);
        myString substr(const char*, int);
        int length();

        int testfunc(int);

    friend ostream& operator<<(ostream&, const myString&);
    friend istream& operator>>(istream&, myString&);
};

#endif // MYSTRING_H_INCLUDED
