#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    string temp;
    while(cin >> temp){
        str += temp;
    }
    cout << str << endl;
    return 0;
}