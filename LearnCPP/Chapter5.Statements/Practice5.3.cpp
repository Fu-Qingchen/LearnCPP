#include<iostream>
using namespace std;
int main(){
    int sum = 0, iter = 0;
    while (sum += ++iter, iter < 10){}
    cout << sum << endl;
    return 0;
}