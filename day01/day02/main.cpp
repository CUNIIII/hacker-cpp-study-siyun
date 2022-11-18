#include <iostream>

/*
 DAY02)
    Function & Namespace 이론 및 실습
 DAY03)
    Class 이론
*/

/*
 <Default Argument>
 int TestFunc(int nParam1=5, int nParam2, int nParam3 = 10); -> 불가능
 int TestFunc(int nParam1=5, int nParam2); -> 가능
 디폴트 매개변수는 오른쪽부터 넣을 수 있다.
*/

// 네임스페이스와 식별자 우선순위
using namespace std;

int nData = 200;

namespace TEST {
    int nData = 100;
    void TestFunc() {
        cout << nData << endl;
    }
}

int main() {
    TEST::TestFunc(); // 100 TEST 네임스페이스 내부 변수 nData가 출력
    return 0;
}
