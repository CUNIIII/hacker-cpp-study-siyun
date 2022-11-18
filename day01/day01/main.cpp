#include <iostream>

/*
 DAY01)
    Dynamic Allocation of Array 이론 및 실습
*/

using namespace std;

int main() {
    
    // 동적 할당 배열
    int n;
    cin >> n;
    int **arr = new int*[n];
    for (int i=0; i<n; i++) {
        arr[i] = new int[n];
        /*
        for (int j=0; j<n; j++) {
            arr[i][j] = i;
        }
        */
        fill_n(arr[i], n, i);
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i=0; i<n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
