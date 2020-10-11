#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(int argc, char* argv[]){
    vector<string> load(ifstream &);
    void savefile(ofstream &, vector<string>);
    ifstream input(argv[1]);

    // Practice 8.7
    // ofstream output(argv[2]);
    // Practice 8.8
    ofstream output(argv[2], ofstream::app);
    
    vector<string> result = load(input);
    for (auto &i : result){
        cout << i << endl;
        cout << "--------------------" << endl;
    }
    savefile(output, result);
    input.close();
    output.close();
    return 0;
}

vector<string> load(ifstream &input){
    vector<string> result;
    string temp;
    while (!input.eof())
    {
        // Practice 8.4
        // getline(input, temp);

        // Practice 8.5
        input >> temp;
        result.push_back(temp);
    }
    return result;
}

// Practice 8.7
void savefile(ofstream &output, vector<string> result){
    for (auto &i : result){
        output << i << " ";
    }
    output << endl;
}