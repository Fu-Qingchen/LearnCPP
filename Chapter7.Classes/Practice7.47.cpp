#include <iostream>
#include <string>
using namespace std;
class Sales_data{
public:
    Sales_data(const string &s,const unsigned &n, double p)
    :bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(): Sales_data("", 0, 0) {}
    explicit Sales_data(const string &s): Sales_data(s, 0, 0){}
    friend ostream & operator << (ostream &, Sales_data &);
private:
    string bookNo;
    unsigned units_sold;
    double revenue;
};
ostream & operator << (ostream & output, Sales_data & sales_data){
    output << sales_data.bookNo << " " << sales_data.units_sold << " " << sales_data.revenue;
    return output;
}
int main() {
    Sales_data sales_data;
    Sales_data sales_data2("Hi");
    cout << sales_data << endl;
    cout << Sales_data("Hello") << endl;
    cout << sales_data2 << endl;
    return 0;
}