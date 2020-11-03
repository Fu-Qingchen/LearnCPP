#include<iostream>
using namespace std;

int *pre_order, *post_order, *in_order, n;

void getData(){
    cin >> n;
    pre_order = new int[n]; post_order = new int[n]; in_order = new int[n];
    for (int i = 0; i < n; i++){ cin >> pre_order[i]; }
    for (int i = 0; i < n; i++){ cin >> post_order[i]; }
}

int search(int *& order, int value, int left, int right){
    for (int i = left; i < right; i++){ if (order[i] == value){ return i; }}
}

void rebuild(int pre_left, int pre_right, int post_left, int post_right, int in_left, int in_right){
    if (in_left + 1 == in_right){ in_order[in_left] = pre_order[pre_left]; return; }
    int new_pre_mid = search(pre_order, post_order[post_right - 2], pre_left, pre_right);
    int length_left_sub = new_pre_mid - (pre_left + 1), sub_parent = pre_order[pre_left];
    int new_post_mid = post_left + length_left_sub;
    int new_in_mid = in_left + length_left_sub;
    rebuild(pre_left + 1, new_pre_mid, post_left, new_post_mid, in_left, new_in_mid);
    rebuild(new_pre_mid, pre_right, new_post_mid, post_right - 1, new_in_mid + 1, in_right);
    in_order[new_in_mid] = sub_parent;
}

int main(){
    getData();
    rebuild(0, n, 0, n, 0, n);
    for (int i = 0; i < n; i++){ cout << in_order[i] << " ";} cout << endl;
}