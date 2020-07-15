#include <iostream>
using namespace std;
int main(){
    int *a = nullptr;
    int aa = 0;
    int aaa = 10;
    cout << aa  << endl; 
    //cout << *a << endl;
    cout << a << endl;
    a = &aa;
    cout << aa  << endl; 
    cout << *a << endl;
    cout << a << endl;
    a = &aaa;
    cout << aaa  << endl; 
    cout << *a << endl;
    cout << a << endl;
    *a = 5;
    cout << aaa  << endl; 
    cout << *a << endl;
    cout << a << endl;
}