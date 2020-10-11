#include<iostream>
using namespace std;
int max(const int var,const int *pvar){
    return var > *pvar ? var : *pvar;
}
void swap(int *&pvar1, int *&pvar2){
    int *tmp = pvar1;
    pvar1 = pvar2;
    pvar2 = tmp;
}
int main(){
    int a = 1, b = 2;
    int *pa = &a, *pb = &b;
    // output 2;
    cout << max(a, &b) << endl;
    // output 1 2
    cout << *pa << " " << *pb << endl;
    swap(pa, pb);
    // output 2 1 
    cout << *pa << " " << *pb << endl;
    return 0;
}

