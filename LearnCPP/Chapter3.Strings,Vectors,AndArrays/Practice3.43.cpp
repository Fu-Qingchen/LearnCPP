#include <iostream>
using namespace std;
int main(){
    int ia[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << "Version 1:" << endl;
    for (const int (&i)[4] : ia)
    {
        for (const int ii : i)
        {
            cout << ii << " ";            
        }
        cout << endl;
    }
    cout << "--------------" << endl;
    cout << "Version 2" << endl;
    for (int i = 0; i < size(ia); i++)
    {
        for (int j = 0; j < size(*ia); j++)
        {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------" << endl;
    cout << "Version 3" << endl;
    for (int (*i)[4] = begin(ia); i < end(ia);i++){
        for (int *j = begin(*i); j < end(*i); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
    return 0;
}