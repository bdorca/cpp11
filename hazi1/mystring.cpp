#include <iostream>
#include <cstring>
#include <stdexcept>
#include "mystring.h"


MyString::MyString() {
//    std::cout<<"Constr: def"<<std::endl;
    stringValue=new StringValue("");
}

MyString::MyString(MyString const &other) {
//    std::cout<<"Constr: copy"<<std::endl;
    stringValue = other.stringValue;
    stringValue->incrCounter();
}

MyString &MyString::operator=(MyString const &other) {
//    std::cout<<"op=: copy"<<std::endl;
    removeSV();
    stringValue = other.stringValue;
    stringValue->incrCounter();
    return *this;
}

MyString::MyString(char const *str) {
//    std::cout<<"Constr: char*"<<std::endl;
    stringValue = new StringValue {str};
}

MyString::MyString(MyString&& other) {
//    std::cout<<"Constr: move"<<std::endl;
    stringValue=other.stringValue;
    other.stringValue=nullptr;

}

MyString& MyString::operator=(MyString&& other) {
//    std::cout<<"op=: move"<<std::endl;
    if(this!=&other) {
        removeSV();
        stringValue=other.stringValue;
        other.stringValue=nullptr;
    }

    return *this;
}


MyString::~MyString() {
//    std::cout << "destr mystring "<<*stringValue << std::endl;
    removeSV();
}

StringValue::StringValue(const char *str) {

    data = new char[strlen(str)+1];
    strcpy(data, str);

    counter = 1;
}

StringValue::StringValue(StringValue const& other) {
    data=new char[strlen(other.data)+1];
    counter=1;
}

StringValue::~StringValue() {
//    std::cout << "destr stringv, Del " << data << std::endl;
    delete[] data;
}


StringValue &StringValue::operator+=(const char *rhs) {
    char *temp = new char[strlen(data)+strlen(rhs)+1];
    strcpy(temp,data);
    strcat(temp,rhs);
    delete[] data;
    data=temp;
    return *this;
}
StringValue StringValue::operator+(const char *rhs) {
    StringValue newSV;
    newSV.data=new char[strlen(data)+strlen(rhs)+1];
    strcpy(newSV.data,data);
    strcat(newSV.data,rhs);
    newSV.counter=1;
    return newSV;
}
StringValue &StringValue::operator+=(StringValue const &rhs) {
    *this+=rhs.data;
    return *this;
}
StringValue* StringValue::operator+(StringValue const &rhs) {
    StringValue* newSV=new StringValue();
    newSV->data=new char[strlen(data)+strlen(rhs.data)+1];
    strcpy(newSV->data,data);
    strcat(newSV->data,rhs.data);
    newSV->counter=1;

    return newSV;
}

MyString &MyString::operator+=(MyString const &rhs) {
    if(stringValue->getCounter()>1) {

        StringValue* temp=new StringValue(*(this->stringValue));
        removeSV();
        stringValue=temp;
    }
    *stringValue+=*(rhs.stringValue);
    return *this;
}
MyString MyString::operator+(MyString const &rhs) {
    MyString ms;
    ms.stringValue=*stringValue+*rhs.stringValue;
    return ms;
}
MyString &MyString::operator+=(const char *rhs) {
    if(stringValue->getCounter()>1) {

        StringValue* temp=new StringValue {*(this->stringValue)};
        removeSV();
        stringValue=temp;
    }
    *stringValue+=rhs;
    return *this;
}
MyString MyString::operator+(const char *rhs) {
    MyString newMS;
    newMS.stringValue=stringValue;
    newMS.stringValue->incrCounter();
    *(newMS.stringValue)+=rhs;
    return newMS;
}

int StringValue::length() {
    return strlen(data);
}
int MyString::length() {
    return stringValue->length();
}

char StringValue::operator[](int i) {
    if(0<=i && i<length()){
        return data[i];
    }else{
        throw std::out_of_range("");
    }
}
char MyString::operator[](int i) {
    return (*stringValue)[i];
}

void MyString::removeSV() {
    if(stringValue) {
        if(!stringValue->decrCounter()) {
            delete stringValue;
        }
    }
}

std::ostream &operator<<(std::ostream &stream, StringValue &sv) {
    stream << sv.data << " " << sv.counter;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, MyString &ms) {
    stream << *ms.stringValue;
    return stream;
}


std::istream& operator>>(std::istream &stream, MyString &ms) {
    ms.removeSV();
    char c[100];
    stream>>c;
    ms.stringValue=new StringValue {c};
    return stream;
}
