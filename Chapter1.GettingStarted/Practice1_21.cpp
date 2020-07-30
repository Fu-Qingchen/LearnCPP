#include<iostream>
#include"Sales_item.h"
using namespace std;
int main(){
    Sales_item item1, item2;
    cout << "Please enter two items:\n";
    cin >> item1 >> item2;
    cout << item1 + item2 << endl;
    return 0;
}