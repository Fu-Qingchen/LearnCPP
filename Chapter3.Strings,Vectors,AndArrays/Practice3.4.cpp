#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.size() == str2.size())
    {
        cout << "True" << endl;
    }
    cout << ((str1.size()>str2.size())?str1:str2);
    return 0;
}