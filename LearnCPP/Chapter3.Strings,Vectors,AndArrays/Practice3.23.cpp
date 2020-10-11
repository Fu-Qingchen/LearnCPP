#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> ivec;
    int temp;
    for (int i = 0; i <10; i++){
        cin >> temp;
        ivec.push_back(temp);
    }
    for (auto it = ivec.begin(); it != ivec.end(); it++)
    {
        *it *= 2;
        cout << *it <<endl;
    }
    return 0;
}