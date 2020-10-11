#include<sstream>
#include<iostream>
using namespace std;
int main(){
    istream & practice(istream &);

    // Practice8.1
    practice(cin);
    // Practice8.9
    istringstream stream("Hello World");
    practice(stream);

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