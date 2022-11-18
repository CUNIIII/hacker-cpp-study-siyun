#include <iostream>

/*
 DAY05)
    Class 실습
*/

class String {
private:
    char* str;
    int len;
    int maxSize;
    
public:
    String(); // default 생성자
    String(int); // 최대 길이 지정 생성자
    ~String(); // 소멸자
    int length(); // 문자열 길이
    void append(char); // 문자열 맨 뒤에 char 변수 추가
    bool find(char); // 문자열 내 특정 char 변수 존재 여부 검사
    void replace(char, char); // 문자열 내 특정 인덱스 대체
    void makeEmpty(); // 문자열 비우기(초기화)
    void print(); // 문자열 출력
    
    String operator + (String &a) {
        String result(len + a.length());
        for (int i=0; i<len; i++) {
            result.append(str[i]);
        }
        for (int i=0; i<a.length(); i++) {
            result.append(a.str[i]);
        }
        return result;
    }
    
    String operator * (int n) {
        String result(len*n);
        while (n--) {
            for (int i=0; i<len; i++) {
                result.append(str[i]);
            }
        }
        return result;
    }
    
    
};

String::String() {
    maxSize = 100;
    str = new char[100];
    len = 0;
}

String::String(int max) {
    maxSize = max;
    str = new char[max];
    len = 0;
}

String::~String() {
    delete[] str;
}

int String::length() {
    return len;
}

void String::append(char x) {
    if (len < maxSize) {
        str[len] = x;
        len++;
    }
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
    String str1(3);
    String str2(2);
    str1.append('a');
    str1.append('b');
    str1.append('c');
    str2.append('d');
    str2.append('e');
    String str3 = str1+str2;
    str3.print();
    String str4 = str3*3;
    str4.print();
}
