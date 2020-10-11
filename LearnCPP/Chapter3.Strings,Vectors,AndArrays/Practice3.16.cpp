#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    for (decltype(v1.size()) i = 0; i < v1.size(); ++i)
    {
        cout << v1[i];
    }
    cout << endl;
    for (decltype(v2.size()) i = 0; i < v2.size(); ++i)
    {
        cout << v2[i];
    }
    cout << endl;
    for (auto i:v3)
    {
        cout << i;
    }
    cout << endl;
    for (decltype(v4.size()) i = 0; i < v4.size(); ++i){
        cout << v4[i];
    }
    cout << endl;
    for (auto i:v5){
        cout << i;
    }
    cout << endl;
    for (auto i:v6){
        cout << i;
    }
    cout << endl;
    for (auto i:v7){
        cout << i;
    }
    cout << endl;
    return 0;
}