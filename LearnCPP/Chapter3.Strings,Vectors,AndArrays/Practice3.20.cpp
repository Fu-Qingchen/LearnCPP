#include <iostream>
#include <vector>
using namespace std;
int main() {
    int temp;
    vector<int> vec;
    vector<int> sum;
    while (cin >> temp) {
        vec.push_back(temp);
    }
    for (decltype(vec.size()) i = 0; i < vec.size(); i++)
    {
        sum.push_back(vec[i] + vec[vec.size() - 1]);
    }
    for (auto i:sum){
        cout << i << endl;
    }
    return 0;
}