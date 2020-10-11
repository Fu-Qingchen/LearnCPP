#include <iostream>
#include <vector>
using namespace std;
int main() {
    int temp;
    vector<int> v;
    while (cin >> temp) {
        v.push_back(temp);
    }
    for (auto &vv:v) 
    {
        cout << vv << endl;
    }
    return 0;
}