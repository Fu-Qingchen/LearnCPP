#include<iostream>
using namespace std;
int main(){
    istream & practice(istream &);
    practice(cin);
    return 0;
}

istream & practice(istream & input){
    char c;
    while(!input.eof()){
        input >> c;
        cout << c;
    }
    input.clear();
    cout << "clear";
    return input;
}