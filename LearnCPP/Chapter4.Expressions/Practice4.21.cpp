#include <iostream>
#include <vector>
using namespace std;
int main(){
    int temp = 0;
    vector <int> ivec;
    for (int i = 0; i < 10; i++)
    {
        ivec.push_back(((temp++)%2) ? 2*temp : temp);
    }
    for (const auto i : ivec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}