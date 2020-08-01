#include <iostream>
#include <vector>
#include <string> 
using namespace std;
int main() {
    string temp;
    vector<string> v;
    while (cin >> temp) {
        v.push_back(temp);
    }
    for (auto &vv:v) 
    {
        cout << vv << endl;
    }
    return 0;
}