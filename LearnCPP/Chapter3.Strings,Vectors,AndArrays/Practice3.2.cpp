#include <iostream>
#include <string>
using namespace std;

int main(){
    string line;
    while(getline(cin, line)){
        cout << line << endl;
    }
    // while(cin >> line){
    //     cout << line << endl;
    // }
    return 0;
}