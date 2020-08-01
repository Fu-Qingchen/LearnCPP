#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    for (auto &s:str)
    {   
        if (isalpha(s))
        {
            s = 'X';
        }
    }
    cout << str << endl;
    return 0;
}