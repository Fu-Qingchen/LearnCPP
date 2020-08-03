#include<iostream>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    try
    {
        if (!n)
        {
            throw runtime_error("Can not divide by zero");
        }
        cout << (m/n) << endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}