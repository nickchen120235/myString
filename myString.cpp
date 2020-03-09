#include "myString.h"

#include <iostream>
using namespace std;

/**< ctor & dtor > */

myString::myString():space(1), p(nullptr){}

myString::myString(const char* str){
    const char* tmp = str;
    do{
        space++;
        tmp++;
    }while(*tmp);

    p = new char[space];

    for(int i = 0; *str != 0; str++, i++){
        p[i] = *str;
    }
    p[space] = '\0';
}

myString::myString(const myString& str):space(str.space), p(new char[space]){
    for(int i = 0; i < space; i++){
        p[i] = str.p[i];
    }
}

myString::~myString(){
    delete[] p;
    p = nullptr;
}

/**< assign and append operators > */

myString myString::operator+(const char* str){
    const char* cur = str;
    do{
        this->space++;
        cur++;
    }while(*cur);
    char* tmp = new char[this->space];

    int index = 0;
    for(int i = 0; this->p[index] != 0; i++){
        tmp[index] = this->p[index];
        index++;
    }

    delete[] this->p;
    this->p = nullptr;

    for(int i = 0; *str != 0; str++, i++){
        tmp[index] = *str;
        index++;
    }
    tmp[this->space] = '\0';

    this->p = tmp;

    return *this;
}

myString myString::operator+(const myString& str){
    this->space += str.space;
    char* tmp = new char[this->space];

    int index = 0;
    for(int i = 0; this->p[index] != 0; i++){
        tmp[index] = this->p[index];
        index++;
    }

    delete[] this->p;
    this->p = nullptr;

    for(int i = 0; str.p[i] != 0; i++){
        tmp[index] = str.p[i];
        index++;
    }
    tmp[this->space] = '\0';

    this->p = tmp;

    return *this;
}

myString myString::operator+=(const char* str){
    const char* cur = str;
    do{
        this->space++;
        cur++;
    }while(*cur);

    char* tmp = new char[this->space];

    int index = 0;
    for(int i = 0; this->p[index] != 0; i++){
        tmp[index] = this->p[index];
        index++;
    }

    delete[] this->p;
    this->p = nullptr;

    for(int i = 0; *str != 0; str++, i++){
        tmp[index] = *str;
        index++;
    }
    tmp[this->space] = '\0';

    this->p = tmp;

    return *this;
}

myString myString::operator+=(const myString& str){
    this->space += str.space;
    char* tmp = new char[this->space];

    int index = 0;
    for(int i = 0; this->p[index] != 0; i++){
        tmp[index] = this->p[index];
        index++;
    }

    delete[] this->p;
    this->p = nullptr;

    for(int i = 0; str.p[i] != 0; i++){
        tmp[index] = str.p[i];
        index++;
    }
    tmp[this->space] = '\0';

    this->p = tmp;

    return *this;
}

myString& myString::operator=(const char* str){
    this->space = 0;

    const char* cur = str;
    do{
        this->space++;
        cur++;
    }while(*cur);
    delete[] this->p;
    this->p = new char[this->space];

    for(int i = 0; *str != 0; str++, i++){
        this->p[i] = *str;
    }
    this->p[this->space] = '\0';

    return *this;
}

myString& myString::operator=(const myString& str){
    this->space = str.space;
    delete[] this->p;
    this->p = new char[str.space];

    for(int i = 0; i < this->space; i++){
        this->p[i] = str.p[i];
        cout << '+';
    }
    cout << endl;
    return *this;
}

/**< relational operators > */

bool myString::operator>(const myString& str){
    if(this->space > str.space)return true;
    if(this->space < str.space)return false;

    for(int i = 0; i < this->space; i++){
        if(this->p[i] > str.p[i])return true;
    }
    return false;
}

bool myString::operator<(const myString& str){
    if(this->space < str.space)return true;
    if(this->space > str.space)return false;

    for(int i = 0; i < this->space; i++){
        if(this->p[i] < str.p[i])return true;
    }
    return false;
}

bool myString::operator<=(const myString& str){
    return !(*this>str);
}

bool myString::operator>=(const myString& str){
    return !(*this<str);
}

bool myString::operator==(const myString& str){
    return (*this>=str) && (*this<=str);
}

bool myString::operator!=(const myString& str){
    return !(*this==str);
}

/**< random access operator > */

char myString::operator[](int index){
    if(index > space){
        cout << "Out of Range!";
        return 0;
    }
    else return this->p[index];
}

/**< istream/ostream overloads > */

ostream& operator<<(ostream& os, const myString& str){
    for(int i = 0; i < str.space; i++){
        os << str.p[i];
    }

    return os;
}

istream& operator>>(istream& is, myString& str){
    int len = 0;
    char **buf = new char*[10];
    int bufSize = 100;
    buf[0] = new char[bufSize];
    int bufX = 0, bufY = 0;
    while(is.peek() != '\n'){
        is >> buf[bufX][bufY];
        len++;
        bufY++;
        if(bufY == 10){
            bufY = 0;
            bufX++;
            bufSize *= 2;
            buf[bufX] = new char[bufSize];
        }
    }

    str.space = len+1;
    str.p = new char[str.space];
    int index = 0;
    for(int i = 0; i <= bufX; i++){
        for(int j = 0; j < 10; j++){
            if(index == len)break;
            str.p[index] = buf[i][j];
            index++;
        }
    }
    str.p[index] = '\0';

    for(int i = 0; i < bufX; i++){
        delete[] buf[i];
    }
    delete[] buf;
    return is;
}

/**< miscellaneous function > */

int myString::length(){
    return this->space;
}

myString myString::substr(int start, int len){
    char* tmp = new char[len+1];
    for(int i = start; i < this->space; i++){
        if(i == start+len)break;
        tmp[i-start] = this->p[i];
    }
    tmp[len] = '\0';
    myString str = tmp;

    return str;
}

myString myString::substr(const char* sub, int len){
    const char* str1 = this->p;
    do{
        if(*str1 == *sub){
            const char *entry1 = str1;
            const char *entry2 = sub;
            do{
                entry1++;
                entry2++;
                if(*entry1 != *entry2)break;
            }while(*entry1 || *entry2);
            if(*entry2 == 0){
                char* tmp = new char[len+1];
                for(int i = 0; i < len; i++){
                    if(*str1 == '\0')break;
                    tmp[i] = *str1;
                    str1++;
                cout << '+' << endl;
                }
                tmp[len] = '\0';
                myString str = tmp;
                return str;
            }
        }
        str1++;
    }while(*str1);
    cout << sub << " not found!!" << endl;
}

int myString::testfunc(int a){return a;}