// # include<iostream>
// # include<cmath>
// # include<vector>
// # include<iomanip>
// # include<cstdlib>

// using namespace std;

// // Problem 1.1
// int selection(vector<unsigned int> &, int);
// // Problem 1.3
// void printRealNumber(double, int);
// int main(){
//     int N = 100;
//     vector<unsigned int> numbers;
//     for (int i = 0; i < N; ++i){
//         numbers.push_back(rand()%N);
//     }
//     cout << selection(numbers, N/2) << endl;
//     cout << "----------------" << endl;
//     for(auto iter = numbers.begin(); iter != numbers.end(); ++iter){
//         cout << *iter << endl;
//     }
//     printRealNumber(-3.1415, 4);
//     return 0;
// }

// // Problem 1.1选择问题, 确定N个数中最大的第k个数
// int selection(vector<unsigned int> & numbers, const int k){
//     for (int i = 0; i < numbers.size(); i++){
//         for (int j = 0; j < numbers.size() - i; j++){
//             if (numbers[j] > numbers[j + 1]){
//                 unsigned int temp = numbers[j];
//                 numbers[j] = numbers[j + 1];
//                 numbers[j + 1] = temp;
//             }
//         }
//     }
//     return numbers[k];
// }

// // Problem 1.3逐字输出实数
// void printRealNumber(double number, int fracPlace){
//     if (number < 0){
//         number = -number;
//     }
//     cout << '-';
//     if (fracPlace == 0)
//     {
//         cout << number;
//     }else{
//         cout << static_cast<int>(number);
//         cout << '.';
//         int number_int = static_cast<int>(fracPlace*10*(number - static_cast<int>(number)));
//         cout << number_int << endl;
//     }

// }

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &);
int lineSearch(vector<int> &, int);
void selectionSort(vector<int> &);
int binarySearch(vector<int> &, int);
void binaryInsertionSort(vector<int> &);
vector<int> mergeSort(vector<int>);
void Heapify(vector<int> &, int, int);
void BuildHeap(vector<int> &);
void HeapSort(vector<int> &);
int getFib(int);
class Fib{
public:
    Fib(int n){
        u = 1, v = 1;
        for (int i = n; i > 0; i--){
        v += u;
        u = v - u;
        }
    }
    int get(){  return u; }
    int next(){ return v; }
    int prev(){ return v - u;}
private:
    int u;
    int v;
};

int main() {
    // // vector<int> test = {1, 2, 3, 4, 5, 27, 31, 32, 40, 196};
    // // cout << binarySearch(test, 7);
    // vector<int> demo{10, 8, 1, 4, 2, 16, 14, 9, 7, 3};
    // // binaryInsertionSort(demo);
    // // vector<int> test(mergeSort(demo));
    // HeapSort(demo);
    // for(auto i:demo){
    //     std::cout << i << " ";
    // }
    // // cout << lineSearch(demo, 31);
    // // std::cout << std::endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Fib(" << i << ") = " << (new Fib(i)) -> get() << endl;
    }
	return 0;
}

void insertionSort(vector<int> &A){
    for (int i = 1; i < A.size(); i++){
        int key = A[i];
        int j = i - 1;
        for (; j >= 0 && key > A[j]; j--){
            A[j + 1] = A[j];
        }
        A[j + 1] = key;
    }
}

void binaryInsertionSort(vector<int> & A){
    for (int i = 1; i < A.size(); i++)
    {
        int center;
        int left = 0;
        int right = i - 1;
        int key = A[i];
        while (left <= right)
        {
            center = (left + right) / 2;
            if (key < A[center])
            {
                right = center - 1;
            }else
            {
                left = center + 1;
            }
        }
        for (int j = i - 1; j > right; j--)
        {
            A[j + 1] = A[j];
        }
        A[right + 1] = key;
    }
}

int binarySearch(vector<int> &A, int n){
    unsigned int left = 0;
    unsigned int right = A.size() - 1;
    unsigned int center = (left + right) / 2;
    while((right - left) > 1){
        if (A[center] > n)
        {
            right = center;
            center = (left + right) / 2;
        }else if (A[center] < n){
            left = center;
            center = (left + right) / 2;
        }else
        {
            break;
        }
        cout << "(" << left << "," << right << ") " << center << endl;
    }
    return center;
}

int lineSearch(vector<int> &A, int number){
    for (int i = 0; i < A.size(); i++){
        if (number == A[i]){
            return i;
        }
    }
}

void selectionSort(vector<int> &A){
    for (int i = 0; i < A.size(); i++){
        int min = A[i];
        for (int j = i; j < A.size(); j++)
        {
            if (min > A[j])
            {
                min = A[j];
                A[j] = A[i];
                A[i] = min;
            }
        }
    }
}

vector<int> mergeSort(vector<int> A){
    if (A.size() == 1) { return A; }
    else{
        vector<int> B(mergeSort(vector<int>(A.begin(), A.begin() + A.size()/2)));
        vector<int> C(mergeSort(vector<int>(A.begin() + A.size()/2, A.end())));
        vector<int> D;
        bool C_flag = true;
        while(B.size() + C.size() != 0){
            if(B.size() == 0 && C_flag){
                D.push_back(C[0]);
                C.erase(C.begin());
            }else if (C.size() == 0){
                D.push_back(B[0]);
                B.erase(B.begin());
                C_flag = false;
            }else if (B[0] < C[0]){
                D.push_back(B[0]);
                B.erase(B.begin());
            }else{
                D.push_back(C[0]);
                C.erase(C.begin());
            }
        }
        return D;
    }
}

void Heapify(vector<int> &A, int i, int n){
    int child_left = 2*i + 1;
    int child_right = 2*i + 2;
    int max = i;
    if (n > child_left && A[max] < A[child_left])
    {
        max = child_left;
    }
    if (n > child_right && A[max] < A[child_right])
    {
        max = child_right;
    }
    if (max != i)
    {
        swap(A[i], A[max]);
        Heapify(A, max, n);
    }
}

void BuildHeap(vector<int> &A){
    int n = A.size();
    for (int i = n/2 - 1; i >= 0; i--)
    {
        Heapify(A, i, n);
    }
}

void HeapSort(vector<int> &A){
    BuildHeap(A);
    for (int i = 0; i < A.size(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        swap(A[i], A[0]);
        Heapify(A, 0, i);
    }
}

int getFib(int n){
    int u = 1, v = 1;
    for (int i = n; i > 0; i--)
    {
        v += u;
        u = v - u;
    }
    return u;
}
