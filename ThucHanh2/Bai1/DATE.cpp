#include "DATE.h"
#include <iostream>
#include <limits>
using namespace std;

int Date::NhapSoNguyen()
{
    int n;
    while (true) {
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Vui long chi nhap so nguyen: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return n;
        }
    }
}

// Check nam nhuan
bool Date::LaNamNhuan(int n)
{
    return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
}

// So ngay trong thang
int Date::TimNgayTrongThang(int t, int n)
{
    switch (t) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return LaNamNhuan(n) ? 29 : 28;
        default: return 31;
    }
}

void Date::Nhap()
{
    //Nhap nam va kiem tra
    do {
        cout << "Nhap nam: ";
        iNam=NhapSoNguyen();
        if (iNam < 1) {
            cout << "Nam phai lon hon 0! Vui long nhap lai.\n";
        }
    } while (iNam < 1);
    //Nhap thang va kiem tra
    do {
        cout<<"Nhap thang: ";
        iThang=NhapSoNguyen();
        if(iThang<1||iThang>12) cout << "Thang phai nam trong khoang[1;12]! Vui long nhap lai.\n";
    }while (iThang<1||iThang>12);
    int ngayMax = TimNgayTrongThang(iThang, iNam);//Ngay toi da trong thang do
    do {
        cout << "Nhap ngay: ";
        iNgay=NhapSoNguyen();
        if (iNgay < 1 || iNgay > ngayMax) {
            cout << "Thang " << iThang << " nam " << iNam
                 << " chi co tu 1 den " << ngayMax << " ngay! Vui long nhap lai.\n";
        }
    } while (iNgay < 1 || iNgay > ngayMax);
    cout<<"Ngay vua nhap la: ";Xuat();
}
Date Date::NgayKeTiep() {
    Date next=*this;
    int ngayMax = TimNgayTrongThang(next.iThang, next.iNam);

    if (next.iNgay < ngayMax) {
        next.iNgay++;
    } else {
        next.iNgay = 1;
        if (next.iThang < 12) {
            next.iThang++;
        } else {
            next.iThang = 1;
            next.iNam++;
        }
    }
    return next;
}
void Date::Xuat()
{
    if(iNgay<10) cout<<"0";
    cout<<iNgay<<"/";
    if(iThang<10) cout<<"0";
    cout<<iThang<<"/";
    if (iNam<10) cout<<"000";
    else if (iNam<100) cout<<"00";
    else if (iNam<1000) cout<<"0";
    cout<<iNam<<"\n";
}
