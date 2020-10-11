#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <string>
#include <list>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

// Practice10.9
void elimDups(vector<string> &);

// Practice10.11
bool isShorter(const string &, const string &);

// Practice10.13
bool isLarger5(const string &);

// Practice10.16
void biggies(vector<string> &, const vector<string>::size_type &);

// Practice10.22
bool isLonger(const string &, const vector<string>::size_type &);

int main()
{
    // Practice 10.1
    vector<int> TestDemo = {1, 2, 3, 4, 1, 2, 3};
    cout << "Practice10.1: " << count(TestDemo.begin(), TestDemo.end(), 2) << endl; // output '2'

    // Practice10.2
    list<string> liststringTest = { "Test", "Hello", "World", "Test"};
    cout << "Practice10.2: " << count(liststringTest.begin(), liststringTest.end(), "Test") << endl; // output '2'
    
    // Practice10.3
    cout << "Practice10.3: " << accumulate(TestDemo.begin(), TestDemo.end(), 0) << endl;

    // Practice10.4
    fill_n(TestDemo.begin(), TestDemo.size(), 0);
    cout << "Practice10.4: ";
    for(auto i : TestDemo){ cout << i << " "; }
    cout << endl;

    // Test Practice 10.9
    string str = "the quick red fox jumps over the slow red turtle";
    istringstream is(str);
    string strtemp;
    vector<string> vecstringTest;
    while(is >> strtemp){ vecstringTest.push_back(strtemp); }
    // elimDups(vecstringTest);

    // // Practice 10.11
    // stable_sort(vecstringTest.begin(), vecstringTest.end(), isShorter);
    // for(auto i : vecstringTest){ cout << i << " "; }
    // cout << endl;

    // // Practice10.13
    // auto small = partition(vecstringTest.begin(), vecstringTest.end(), isLarger5);
    // vecstringTest.erase(small, vecstringTest.end());
    // for(auto i : vecstringTest){ cout << i << " "; }
    // cout << endl;

    // Practice10.14
    auto f14 = [](const int &a, const int &b){ return a + b; };
    cout << f14(1,2) << endl;

    // Practice10.15
    int i15 = 1;
    auto f15 = [i15](const int &a){ return a + i15; };
    cout << f15(2) << endl;

    // Practice10.16
    biggies(vecstringTest, 4);

    // Practice10.21
    int i21 = 5;
    auto f21 = [&i21](){ return i21 == 0 ? true: !(i21--); };
    while(!f21()){ cout << i21 << " ";}
    return 0;
}

// Practice10.9
void elimDups(vector<string> &vec){
    // Practice 10.9
    sort(vec.begin(), vec.end());
    auto temp = unique(vec.begin(), vec.end());
    vec.erase(temp, vec.end());
}

// Practice 10.11
bool isShorter(const string & str1, const string & str2){
    return str1.size() < str2.size();
}

// Practice 10.13
bool isLarger5(const string & str1){
    return str1.size() >= 5;
}

// Practice 10.16 输出序列vec中长度大于n的元素
void biggies(vector<string> &vec, const vector<string>::size_type &n) {
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(),[](const string &a, const string &b){ return a.size() < b.size(); });
    // auto iterator = find_if(vec.begin(), vec.end(),[n](const string &str){ return str.size() >= n; });
    auto iterator = partition(vec.begin(), vec.end(), [n](const string &str){ return str.size() < n; });
    // auto count16 = count_if(vec.begin(), vec.end(), [n](const string &str){ return str.size() >= n; });
    auto count16 = count_if(vec.begin(), vec.end(), bind(isLonger, _1, n));
    cout << "count: " << count16 << endl;
    while (iterator!=vec.end()) { cout << *iterator++ << " "; }
    cout << endl;
}

// Practice 10.22
bool isLonger(const string &str, const vector<string>::size_type & size){
    return str.size() >= size;
}