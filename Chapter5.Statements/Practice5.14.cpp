#include<iostream>
#include<string>
using namespace std;
int main(){
    int count = 1, maxcount = 1;
    string nowstr, countstr;
    cin >> nowstr;
    countstr = nowstr;
    while (cin >> nowstr)
    {
        if (nowstr == countstr)
        {
            count++;
            if (count > maxcount)
            {
                maxcount = count;
            }
            
        }else
        {
            count = 1;
            countstr = nowstr;
        }
    }
    cout << maxcount <<endl;
    return 0;
}