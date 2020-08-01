#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> ivec;
    int temp;
    while (cin >> temp)
    {
        ivec.push_back(temp);
    }
    for (auto it = ivec.begin(); it != ivec.end() - 1; it++)
    {
        *it += *(it + 1);
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}