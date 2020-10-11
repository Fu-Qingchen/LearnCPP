#include<iostream>
using namespace std;
int main(){
    cout<<"Plasses enter two numbers"<<endl;
    int v1 = 0, v2 = 0;
    cin>>v1>>v2;
    int sum = 0;
    while(v1<=v2){
        sum += v1++;
    }
    cout<<"The sum of the numbers between two numbers is "<<sum<<endl;
    return 0;
}