#include <iostream>
#include <math.h>
using namespace std;
using INT = int;
INT main() {
    INT i = 0;
    const INT v2 = 0;
    INT v1 = v2;
    INT *p1 = &v1, &r1 = v1;
    const INT *p2 = &v2, &r2 = v2, *const p3 = &i;
    r1 = v2;
    p1 = p2, p2 = p1;
    p1 = p3, p2 = p3;
    constexpr double d = sqrt(3);
    INT null = 0, *p = null;
    p1 = 42;
}