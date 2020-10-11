// # Descriptioin
// Let S be a set of n integral points on the x-axis. For each given interval [a, b], you are asked to count the points lying inside.

// # Input
// The first line contains two integers: n (size of S) and m (the number of queries).
// The second line enumerates all the n points in S.
// Each of the following m lines consists of two integers a and b and defines an query interval [a, b].

// # Output
// The number of points in S lying inside each of the m query intervals.

// # Example
// ## Input
// 5 2
// 1 3 7 9 11
// 4 6
// 7 12

// ## Output
// 0
// 3

// #Restrictions
// 0 <= n, m <= 5 * 10^5
// For each query interval [a, b], it is guaranteed that a <= b.
// Points in S are distinct from each other.
// Coordinates of each point as well as the query interval boundaries a and b are non-negative integers not greater than 10^7.
// Time: 2 sec
// Memory: 256 MB

#include<iostream>
#include<stdio.h>
using namespace std;

void sort(int, int);
int find(int, bool, int, int);

int array[500000];

int main(){
   int n, m;
   scanf("%d %d\n", &n, &m);
   for (int i = 0; i < n; i++){
      scanf("%d", &array[i]);
   }
   sort(0, n);
   for (int i = 0; i < m; i++)
   {
      int a, b;
      scanf("%d %d", &a, &b);
      int tempb = find(b, false, 0, n);
      int tempa = find(a, true, 0, tempb);
      printf("%d\n", tempb - tempa);
   }
   return 0;
}

void sort(int begin, int end){
   int mid = (begin + end) >> 1;
   if (end - begin < 2) { return; }
   sort(begin, mid);
   sort(mid, end);
   int *tempArray = new int[end - begin];
   int i = 0, j = 0;
   while (!((i == mid - begin) && (j == end - mid)))
   {
      if (j == end - mid || (i != mid - begin && array[begin + i] < array[mid + j]))
      {
         tempArray[i + j] = array[begin + i];
         ++i;
      }
      if (j == end - mid && i == mid - begin)
      {
         break;
      }
      if (i == mid - begin || (j != end - mid && array[begin + i] > array[mid + j]))
      {
         tempArray[i + j] = array[mid + j];
         ++j;
      }
   }
   for (int i = 0; i < end - begin; i++)
   {
      array[begin + i] = tempArray[i];
   }
   delete tempArray;
}

int find(int e, bool isLeft, int low, int high){
   int left = low, right = high;
   while (left < right){
      int mid = (left + right) >> 1;
      if (e < array[mid]){
         right = mid;
      }else{ left = mid + 1; }
   }
   if (isLeft)
   {
      if (e == 0)
      {
         return low;
      }
      while (array[--left] == e) {}
      ++left;
   }
   return left;
}