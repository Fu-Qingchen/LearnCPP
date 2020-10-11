#include<iostream>
using namespace std;
int main(){
    int sum = 0;
    int i = 50;
    while (i<=100) {
        sum += i++;
        cout<<i<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
