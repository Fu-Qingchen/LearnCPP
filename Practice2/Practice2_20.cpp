#include <iostream>
using namespace std;
int main() {
    int i = 42;
    int* pl = &i;
    *pl = *pl * *pl;
    cout << i << endl;
    cout << *pl << endl;
    cout << pl << endl;
    int i = -1, &r = 0; // a
    int i2;
    int *const p2 = &i2;    //b
    const int i = -1, &r = 0; 
    const int *const p3 = &i2;
    const int &const r2;
    const int i2 = i, &r = i;
    const int *a;
}