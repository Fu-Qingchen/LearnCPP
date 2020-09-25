#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char *argv[]){
    ifstream input(argv[1]);
    string line, temp;
    vector<string> lines;
    while (getline(input, line))
    {
        istringstream iss(line);
        while (iss >> temp)
        {
            lines.push_back(temp);
        }
    }
    for (auto &i : lines)
    {
        cout << i << endl;
    }
    return 0;
}