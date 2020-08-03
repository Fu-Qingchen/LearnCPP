#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    char c;
    int aCnt = 0, enters = 0, space = 0, fCnt = 0;
    bool fflag = false;
    // 输入在命令行里面的空格、换行和制表等会被默认去掉
    while (cin >> noskipws >> c)
    {
        switch (c)
        {
            case 'a': case 'e': case 'o': case 'u': 
            case 'A': case 'E': case 'I': case 'O': case 'U':
                ++aCnt;
                fflag = false;
                break;
            case '\n':
                ++enters; 
                fflag = false;
                break;
            case ' ': 
                ++space; 
                fflag = false;
                break;
            case 'i': 
                ++aCnt;  
                if (fflag) { ++fCnt;}
                fflag = false;
                break;
            case 'f': 
                if (fflag) { ++fCnt;}  
                fflag = true;
                break;
            case 'l':
                if (fflag) { ++fCnt;}  
                fflag = false; 
                break;       
            default: 
                fflag = false;
                break;
        }
    }
    cout << setw(5) << aCnt << setw(5) << enters << 
    setw(5) << space << setw(5) <<fCnt << endl;
    return 0;
}