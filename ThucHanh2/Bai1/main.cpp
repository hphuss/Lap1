#include <iostream>
#include "DATE.h"
using namespace std;

int main()
{
    Date d1;
    d1.Nhap();
    Date d2;
    d2 = d1.NgayKeTiep();
    cout<<"Ngay ke tiep la: "; d2.Xuat();
    return 0;
}
