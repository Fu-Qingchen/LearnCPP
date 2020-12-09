#include<iostream>
using namespace std;

class AB
{
private:
    /* data */
public:
    AB(){
        cout << "!" << endl;
    };
    AB(int a){
            cout << a << endl;
    }
};

int main(){
    AB a(10), *b = &a, &p = a;
}