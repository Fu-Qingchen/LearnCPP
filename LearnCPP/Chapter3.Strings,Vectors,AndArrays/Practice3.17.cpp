#include <iostream>
#include <vector>
#include <string> 
#include <cctype>
using namespace std;
int main() {
    string temp;
    vector<string> v;
    while (cin >> temp) {
        v.push_back(temp);
    }
    for (auto &vv:v) 
    {   
        for (auto &vvv:vv){
            vvv = toupper(vvv);
        }
        cout << vv << endl;
    }
    return 0;
}