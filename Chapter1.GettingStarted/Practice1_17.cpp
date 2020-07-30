#include<iostream>
using namespace std;
int main(){
    int vale = 0;
    int temp = 0;
    int count = 1;
    cin>>vale;
    temp = vale;
    while(cin >> vale){
        if (temp == vale)
        {
            count++;
        }else
        {
            cout << temp << " occurs " << count << " times." << endl;
            count = 1;
            temp = vale;
        }
    }
    cout << temp << " occurs " << count << " times." << endl;
    cout << "Finished" << endl;
    return 0;
}