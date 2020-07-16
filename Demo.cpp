#include<iostream>
using namespace std;
template <typename T1, typename T2>

double demo(T1 a, T2 b) {
    return T1(a + b);
}

int main(){
    int calcualate(int);
    int n;
    double nn;
    cin >> n;
    cout << calcualate(n) << endl;
    nn = demo(1, 2.5);
}

int calcualate(int n){
    if (n == 1)
    {
        return 1;
    }
    else{
        return calcualate(n-1) + n*n;
    }
}