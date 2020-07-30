#include<iostream>
using namespace std;
int main(){
    int sum = 0;
    int i = 10;
    while (i > 0) {
        sum += i--;
    }
    cout<<sum<<endl;
    return 0;
}
