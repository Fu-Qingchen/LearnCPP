#include<iostream>
#include"Sales_item.h"
using namespace std;
int main(){
    Sales_item mainSales_item, tempSales_item;
    string output;
    cout << "Please enter items(Enter '0' to quit): \n";
    cin >> mainSales_item;
    tempSales_item = mainSales_item;
    string str;
    while(cin>>tempSales_item){
        if (tempSales_item.isbn() == mainSales_item.isbn())
        {
            mainSales_item += tempSales_item;
        }else{
            cout << mainSales_item << endl;
            mainSales_item = tempSales_item;
        }
    }
    return 0;
}