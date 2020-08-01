#include <iostream>
#include <vector>
using namespace std;
int main(){
    int temp;
    int a[3] = { 1, 2, 3 };
    int b[3];
    b = a;
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