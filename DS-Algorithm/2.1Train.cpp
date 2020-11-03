#include<iostream>
#include <cstdio>

class MyStack{
public:
    MyStack(int capacityValue){ setCapacity(capacityValue); }
    ~MyStack(){ delete [] data; }
    void push(int value){ data[size] = value; ++size;}
    int pop(){ --size; return data[size]; }
    int top(){ return data[size - 1]; }
    void setCapacity(int capacityValue){ data = new int[capacityValue]; }
    int getSize(){ return size; }
private:
    int *data = nullptr;
    int size = 0;
};

int main(){
    int m, n, temp, Aitem = 0, j = 0;
    scanf("%d %d", &m, &n);
    MyStack S(m), B(m), tempB(m);
    for (int i = 0; i < m; ++i){ scanf("%d", &temp); B.push(temp); }
    while (B.getSize() != 0) { tempB.push(B.pop()); }
    bool isSucc = true, *process = new bool[m << 1];
    while (tempB.getSize() != 0){
        if (n == 0){ isSucc = false; break; }
        else{
            if ((++Aitem > m) || (S.getSize() > (n - 1))){ isSucc = false; break; }
            S.push(Aitem); process[j++] = true;
            while (tempB.top() == S.top()) { 
                tempB.pop(); S.pop(); 
                process[j++] = false;
                if (S.getSize() == 0){ break; }}}}
    if (isSucc){ 
        for (int i = 0; i < m << 1; i++){
            if (process[i]){ printf("push\n"); }
            else { printf("pop\n"); }}
            delete [] process;}
    else{ printf("No\n"); }
}