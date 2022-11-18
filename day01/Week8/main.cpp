#include <iostream>

/*
 DAY05)
    Class 실습
*/

class String {
private:
    char* str;
    int len;
    
public:
    String(); // default 생성자
    String(const String&); // 최대 길이 지정 생성자
    ~String(); // 소멸자
    int length(); // 문자열 길이
    void append(char); // 문자열 맨 뒤에 char 변수 추가
    bool find(char); // 문자열 내 특정 char 변수 존재 여부 검사
    void replace(char, char); // 문자열 내 특정 인덱스 대체
    void makeEmpty(); // 문자열 비우기(초기화)
    void print(); // 문자열 출력
    
    String operator = (String &s) {
        len = s.len;
        char *temp = str;
        str = s.str;
        delete[] temp;
        return *this;
    }
    
};

String::String() {
    str = nullptr;
    len = 0;
}

String::String(const String& org) {
    this->len = org.len;
    str = new char[this->len];
    for (int i = 0; i < this->len; i++){
       str[i] = org.str[i];
    }
}

String::~String() {
    delete[] str;
}

int String::length() {
    return len;
}

void String::append(char x) {
    char *temp = str;
    str = new char[len+1];
    for (int i=0; i<len; i++) {
        str[i] = temp[i];
    }
    str[len] = x;
    delete[] temp;
    len++;
}

bool String::find(char x) {
    for (int i = 0; i < len; i++) {
        if (str[i] == x) {
            return true;
        }
    }
    return false;
}

void String::replace(char x, char y) {
    for (int i=0; i<len; i++) {
        if (str[i] == x) {
            str[i] = y;
        }
    }
}

void String::makeEmpty() {
    for (int i=0; i<len; i++) {
        str[i] = '\0';
    }
    len = 0;
}

void String::print() {
    for (int i=0; i<len; i++) {
        std::cout << str[i];
    }
    std::cout << '\n';
}


int main() {
    String s1, s2;
    s1.append('x');
    s1.append('x');
    s2.append('y');
    s1 = s2;
    s1.print();
}
