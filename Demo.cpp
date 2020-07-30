// #include<iostream>
// using namespace std;
// template <typename T1, typename T2>

// double demo(T1 a, T2 b) {
//     return T1(a + b);
// }

// int main(){
//     // int calcualate(int);
//     // const int n = 3;
//     // int a[n*2];
//     // double nn;
//     // // cin >> n;
//     // cout << calcualate(n) << endl;
//     // nn = demo(1, 2.5);
//     void select_sort(int array[], int n);
//     int array[10];
//     for (int i = 0; i < 10; i++)
//     {
//         cin >> array[i];
//     }
//     select_sort(array, 10);
//     for (int i = 0; i < 10; i++)
//     {
//         cout << array[i] << endl;
//     }
//     char str_demo[] = "Hello World";
//     return 0;
// }

// int calcualate(int n){
//     if (n == 1)
//     {
//         return 1;
//     }
//     else{
//         return calcualate(n-1) + n*n;
//     }
// }

// void select_sort(int array[], int n){
//     int i, j, k, t;
//     for ( i = 0; i < n - 1; i++)
//     {
//         k = i;
//         for ( j = i + 1; j < n; j++)
//         {
//             if (array[j] < array[k])
//             {
//                 k = j;
//             }
//             t = array[k];
//             array[k] = array[i];
//             array[i] = t;
//         }
//     }
// }

// #include<iostream>
// #include<string>
// using namespace std;
// int main() {
// 	void sort(char *[], int);
// 	void show(char *[], int);
// 	char *str[] = { "A", "B", "C++", "C", "D", "E", "CA", "G", "H"};
// 	int n = 9;
// 	sort(str, n);
// 	show(str, n);
// 	return 0;
// }

// void sort(char *str[], int n) {
// 	char *temp;
// 	for (int i = 0; i < n - 1; i++)
// 	{
// 		for (int j = 0; j < n - i - 1; j++)
// 		{
// 			if (strcmp(str[j], str[j + 1]) > 0)
// 			{
// 				temp = str[j]; str[j] = str[j + 1]; str[j + 1] = temp;
// 			}

// 		}
// 	}

// }

// void show(char *str[], int n) {
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << str[i] << endl;
// 	}
// }

// Practice 6.4
#include<iostream>
#include<iomanip>
using namespace std;
void transform(int *, const int, const int);
int main() {
	const int n = 10, m = 6;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	transform(a, n, m);
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << a[i];
	}
	cout << endl;
	return 0;
}
void transform(int *numbers, const int n, const int m) {
	// int temp_[m];
	int *temp = new int[m];
	for (int i = 0; i < m; i++)
	{
		temp[i] = numbers[n - m + i];
	}
	for (int i = 0; i < n - m; i++)
	{
		numbers[n - i - 1] = numbers[n - m - i - 1];
	}
	for (int i = 0; i < m; i++)
	{
		numbers[i] = temp[i];
	}
	delete[] temp;
}v