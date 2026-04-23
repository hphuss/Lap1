#include "Ngay.h"
#include <iostream>
#include <limits>
using namespace std;

cNgay::cNgay(int n, int t, int nm) : ngay(n), thang(t), nam(nm) {}

int cNgay::NhapSoNguyen()
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
bool cNgay::LaNamNhuan(int n) const
{
    return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
}

// So ngay trong thang
int cNgay::TimNgayTrongThang(int t, int n) const
{
    switch (t) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return LaNamNhuan(n) ? 29 : 28;
        default: return 31;
    }
}

void cNgay::Nhap()
{
    // Nhap nam va kiem tra
    do {
        cout << "    Nhap nam: ";
        nam = NhapSoNguyen();
        if (nam < 1) {
            cout << "Nam phai lon hon 0! Vui long nhap lai.\n";
        }
    } while (nam < 1);

    // Nhap thang va kiem tra
    do {
        cout << "    Nhap thang: ";
        thang = NhapSoNguyen();
        if (thang < 1 || thang > 12) {
            cout << "Thang phai nam trong khoang [1;12]! Vui long nhap lai.\n";
        }
    } while (thang < 1 || thang > 12);

    int ngayMax = TimNgayTrongThang(thang, nam); // Ngay toi da trong thang do

    // Nhap ngay va kiem tra
    do {
        cout << "    Nhap ngay: ";
        ngay = NhapSoNguyen();
        if (ngay < 1 || ngay > ngayMax) {
            cout << "Thang " << thang << " nam " << nam
                 << " chi co tu 1 den " << ngayMax << " ngay! Vui long nhap lai.\n";
        }
    } while (ngay < 1 || ngay > ngayMax);
}

void cNgay::Xuat() const {
    if (ngay < 10) cout << "0";
    cout << ngay << "/";
    if (thang < 10) cout << "0";
    cout << thang << "/" << nam;
}

bool cNgay::LonTuoiHon(const cNgay& khac) const {
    if (nam != khac.nam) return nam < khac.nam;
    if (thang != khac.thang) return thang < khac.thang;
    return ngay < khac.ngay;
}
