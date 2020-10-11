#include <iostream>
#include <vector>
using namespace std;
int main(){
    int temp;
    vector<int> v(11, 0);
    auto it = v.begin();
    while (cin >> temp)
    {
        cout << temp << " ";
        if (temp <= 100)
        {
            *(it + temp/10) += 1;
            cout << *(it + temp/10) << " ";
        }
    }
    for (auto cit = v.cbegin(); cit != v.cend(); cit++)
    {
        cout << *cit << " ";
    }
    cout << endl;
    return 0;
}