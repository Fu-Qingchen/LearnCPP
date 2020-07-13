#include<iostream>
using namespace std;
int main(){
    cout<<"Plasses enter two numbers"<<endl;
    int n  = 0, m = 0;
    cin>>n>>m;
    int sum = 0;
    if (n<m){
        for(int i = n; i <= m;++i)
        {
        sum += i;
        }
    }else{
        for (int i = m; i <= n; i++)
        {
            sum += i;
        }
    }
    cout<<sum<<endl;
    return 0;
}