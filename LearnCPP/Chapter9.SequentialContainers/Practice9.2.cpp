#include <deque>
#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
using namespace std;

// Practice 9.4
bool findItem4Vector(const vector<int> &, int);
// Practice 9.5
void findItem4VectorPro(const vector<int> &, int);
// Practice 9.28
void Practice9_28(forward_list<string> &, const string &, const string &);
int main(){
    // Practice 9.2
    list<deque<int>> mlist{{1, 2, 3, 4}, {5, 6, 7, 8}};
    // Test Practice 9.2
    for (auto md : mlist){
        for (auto mi : md) { cout << mi << " ";}
        cout << endl;
    }

    // Test Practice 9.4
    vector<int> mvector{1, 2, 3, 4};
    cout << findItem4Vector(mvector, 0) << " ";
    cout << findItem4Vector(mvector, 1) << endl;

    // Test Practice 9.5
    findItem4VectorPro(mvector, 0);
    findItem4VectorPro(mvector, 1);

    // Practice 9.11
    vector<int> v1;
    vector<int> v2(v1);
    vector<int> v3 = v2;
    vector<int> v4{1, 2, 3, 4};
    vector<int> v5 = {5, 6, 7, 8};
    vector<int> v6(v5.begin(), v5.end());
    for(auto i:v1) { cout << "v1:" << i << " ";}; cout << endl;
    for(auto i:v2) { cout << "v2:" << i << " ";}; cout << endl;
    for(auto i:v3) { cout << "v3:" << i << " ";}; cout << endl;
    for(auto i:v4) { cout << "v4:" << i << " ";}; cout << endl;
    for(auto i:v5) { cout << "v5:" << i << " ";}; cout << endl;
    for(auto i:v6) { cout << "v6:" << i << " ";}; cout << endl;

    // Practice 9.13
    vector<int> vint = {1, 2, 3, 4, 5,};
    vector<double> vdouble(vint.begin(), vint.end());
    cout << "vint:"; for(auto i:vdouble) { cout << i << " ";}; cout << endl;

    // Practice9.14
    list<char *> list1 = {"Hello", "World"};
    vector<string> vector_string(list1.begin(), list1.end());
    vector<string> vector_string2;
    vector_string2.assign(list1.begin(), list1.end());
    for(auto i:list1) { cout << i << " ";}; cout << endl;
    for(auto i:vector_string) { cout << i << " ";}; cout << endl;
    for(auto i:vector_string2) { cout << i << " ";}; cout << endl;

    // Practice 9.15
    vector<int> vint2 = {1, 2, 3, 4};
    vector<int> vint3(vint);
    cout << "Practice 9.15: " << (vint == vint2) << " " << (vint == vint3) << endl;

    // Practice 9.16
    list<int> lint;
    lint.assign(vint.begin(), vint.end());
    list<int> lint2{1, 2, 3, 4};
    cout << "Practice 9.16: " << (lint == list<int>(vint.begin(), vint.end())) << " ";
    cout << (lint2 == list<int>(vint.begin(), vint.end())) << endl;

    // Practice 9.18
    string tempsstring;
    // deque<string> inputDeque;
    // while (cin >> tempsstring){ inputDeque.push_back(tempsstring); }
    // cout << "Practice 9.18: ";
    // for(auto it = inputDeque.begin(); it !=inputDeque.end(); it++){ cout << *it << "|"; }
    // cout << endl;

    // Practice 9.19
    // list<string> inputlist;
    // while(cin >> tempsstring){ inputlist.push_back(tempsstring); }
    // cout << "Practice 9.19: ";
    // for(auto it = inputlist.begin(); it !=inputlist.end(); it++){ cout << *it << "|"; }
    // cout << endl;

    // Practice 9.20
    list<int> listInt{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    deque<int> dequeIntEven, dequeIntOdd;
    for(auto it = listInt.begin(); it !=listInt.end(); it++){ *it%2 ?dequeIntOdd.push_back(*it) : dequeIntEven.push_back(*it); }
    cout << "Practice 9.20: " << endl;
    cout << "Even: ";
    for (auto item : dequeIntEven){ cout << item << " ";}
    cout << endl;
    cout << "Odd: ";
    for (auto item : dequeIntOdd){ cout << item << " ";}
    cout << endl;
    
    // Practice 9.24
    // cout << "Practice 9.24: " << v1.at(0) << v1[0] << *(v1.begin()) << v1.front() << endl;

    // Practice 9.26
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> via;
    list<int> lia;
    for(auto i : ia){ via.push_back(i); lia.push_back(i); }
    for(auto it = via.begin(); it != via.end();){ if(*it % 2 == 0) it = via.erase(it); else ++it; }
    for(auto it = lia.begin(); it != lia.end();){ if(*it % 2) it = lia.erase(it); else ++it; }
    cout << "Practice 9.26: " << endl;
    cout << "vector<int>: ";
    for (auto item : via){ cout << item << " ";}
    cout << endl;
    cout << "list<int>: ";
    for (auto item : lia){ cout << item << " ";}
    cout << endl;

    // Practice 9.27
    forward_list<int> flia;
    auto iter4flia = flia.before_begin();
    for(auto i : ia){ iter4flia = flia.insert_after(iter4flia, i); }
    cout << "Practice 9.27: " << endl;
    cout << "Before: ";
    for (auto item : flia){ cout << item << " ";}
    cout << endl;
    iter4flia = flia.before_begin();
    for(auto it = flia.begin(); it != flia.end();){ if(*(it) % 2) it = flia.erase_after(iter4flia); else iter4flia = it++; }
    cout << "After: ";
    for (auto item : flia){ cout << item << " ";}
    cout << endl;

    // Test Practice 9.28
    forward_list<string> testforward_list{"Test", "Hello","World"};
    string finder = "Hello";
    string inserter = "This";
    cout << "Practice 9.28: " << endl;
    cout << "Before: ";
    for (auto item : flia){ cout << item << " ";}
    cout << endl;
    Practice9_28(testforward_list, inserter, finder);
    cout << "Turn 1: ";
    for (auto item : testforward_list){ cout << item << " ";}
    cout << endl;
    Practice9_28(testforward_list, finder, inserter);
    cout << "Turn 2: ";
    for (auto item : testforward_list){ cout << item << " ";}
    cout << endl;

    for(int i = 0; i < 10; ++i){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

bool findItem4Vector(const vector<int> & v, int n){
    for(auto iterator = v.cbegin(); iterator!=v.cend(); iterator++){
        if(*iterator == n){ return true; }
    }
    return false;
}

void findItem4VectorPro(const vector<int> & v, int n){
    for(auto iterator = v.cbegin(); iterator!=v.cend(); iterator++){
        if(*iterator == n){ cout << *iterator; return; }
    }
    cout << "Not Find It" << endl;
}

void Practice9_28(forward_list<string> & list,const string & str1,const string & str2){
    bool found = false;
    auto prev = list.before_begin();
    for(auto iterator = list.begin();iterator != list.end(); iterator++){
        if (*iterator == str1){
            list.insert_after(iterator,str2);
            found = true;
        }
        prev = iterator;
    }
    if (!found){
        list.insert_after(prev,str2);
    }
}