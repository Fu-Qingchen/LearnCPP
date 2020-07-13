#include<iostream>
#include"Sales_item.h"
using namespace std;
int main(){
    Sales_item mainSales_item, tempSales_item;
    cout << "Please enter items: \n";
    cin>>mainSales_item;
    tempSales_item = mainSales_item;
    while(cin>>tempSales_item){
        mainSales_item += tempSales_item;
    }
    cout << mainSales_item << endl;
    return 0;
}