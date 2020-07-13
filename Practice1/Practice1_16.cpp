#include <iostream>
using namespace std;
int main(){
    int sum = 0, input = 0;
    while(cin >> input){
        sum += input;
    }
    cout << sum <<endl;
    return 0;
}