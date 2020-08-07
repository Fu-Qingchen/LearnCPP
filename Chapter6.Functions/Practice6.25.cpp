#include<iostream>
#include<string>
#include<vector>
using namespace std;
int a[10];
int (*transform(int))[10];

// the display() of A using the item in B
class A
{
private:
public:
    A();
    void display();
};

class B
{
private:
    int b = 0;
public:
    friend void A::display();
    B();
};

void A::display(){
    B b;
    cout << b.b << endl;
}

typedef string Type;
Type initVal();
class Execise
{
private:
    int val;
public:
    typedef int Type;
    Type setVal(Type);
    Type initVal();
};
Execise::Type Execise::setVal(Type parm){
    val = parm + initVal();
}

class NoDefault
{
private:
    /* data */
public:
    NoDefault(int);
    NoDefault();
};

class C
{
private:
    /* data */
public:
    C(int i):noDefault(i){}
    NoDefault noDefault;
};

vector<NoDefault> vec(10);

int main(int argc, char **argv){
    int p = 10;
    const int a = p;
    int b = a;
    cout << p << a << b << endl;
    string str;
    for (int i = 1; i < argc; ++i)
    {
        str += argv[i];
    }
    int (*point)[10] = transform(3);
    for (int i = 0; i < 10; i++)
    {
        cout << (*point)[i] << " ";
    }
    cout << str << endl;
    return 0;
}

// intput: multi
// output: multi*{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
int (*transform(int m))[10]{
    for (int i = 0; i < 10; i++)
    {
        a[i] = m*i;
        cout << a[i] << " ";
    }
    return &a;
}