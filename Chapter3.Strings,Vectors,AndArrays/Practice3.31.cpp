#include<iostream>
using namespace std;
int main(){
    int n[10];
    int *n2 = n;
    for (int i = 0; i < size(n);i++){
        n[i] = i;
        cout << n2[i] << endl;
    }
    for (auto p = begin(n); p < end(n); p++)
    {
        *p = 0;
    }
    for(auto i:n){
        cout << i << endl;
    }
    return 0;
}