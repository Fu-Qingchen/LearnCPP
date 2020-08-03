#include <iostream>
using namespace std;
int main() {
    int i, &rei = i;
    i = 5; rei = 10;
    cout << i << " " << rei << endl;
}