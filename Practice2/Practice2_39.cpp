#include<iostream>
using namespace std;
struct Foo
{
    int number;
    int value;
    string name;
};

int main() {
    Foo foo1, foo2, foo3;
    cout << max(1,2) << endl;
    return 0;
}

int max(int a, int b) {
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}
