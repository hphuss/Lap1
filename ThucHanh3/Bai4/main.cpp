#include <iostream>
#include <limits>
#include <string>
#include "Array.h"

using namespace std;

// Ham ho tro nhap so nguyen, tu dong bat loi neu nhap chu
int NhapSoNguyen(const string& thongBao, int minVal = -999999) {
    int giaTri;
    while (true) {
        cout << thongBao;

        // Buoc 1: Kiem tra xem nguoi dung co nhap dung dinh dang so khong
        if (cin >> giaTri) {

            // Buoc 2: Kiem tra xem so do co thoa man dieu kien minVal khong (De phan biet nhap n va nhap x)
            if (giaTri >= minVal) {
                return giaTri;
            } else {
                cout << "Vui long nhap so nguyen duong!\n";
            }

        } else {
            // Neu nhap sai kieu du lieu (vi du: nhap chu)
            cout << "Vui long chi nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    cout << "--- CHUONG TRINH XU LY MANG 1 CHIEU ---\n\n";
    cArray arr;

    // 1. Tao mang ngau nhien
    int n = NhapSoNguyen("Nhap so luong phan tu cua mang (n > 0): ", 1);
    arr.TaoNgauNhien(n);

    // 2. Xuat mang
    cout << "\n1. Mang vua tao ngau nhien: ";
    arr.XuatMang();

    // 3. Dem so lan xuat hien
    cout << "\n--- DEM GIA TRI ---\n";
    int x = NhapSoNguyen("Nhap gia tri x can dem: ");
    int soLan = arr.DemGiaTri(x);
    cout << "So lan xuat hien cua " << x << " trong mang la: " << soLan << "\n";

    // 4. Kiem tra tang dan
    cout << "\n--- KIEM TRA TANG DAN ---\n";
    if (arr.KiemTraTangDan()) {
        cout << "Cac phan tu trong mang dang tang dan.\n";
    } else {
        cout << "Cac phan tu trong mang KHONG tang dan.\n";
    }

    // 5. Tim phan le nho nhat
    cout << "\n--- TIM SO LE NHO NHAT ---\n";
    int leMin;
    if (arr.TimLeNhoNhat(leMin)) {
        cout << "So le nho nhat trong mang la: " << leMin << "\n";
    } else {
        cout << "Mang khong co so le nao.\n";
    }

    // 6. Tim nguyen to lon nhat
    cout << "\n--- TIM SO NGUYEN TO LON NHAT ---\n";
    int ntMax;
    if (arr.TimNguyenToLonNhat(ntMax)) {
        cout << "So nguyen to lon nhat trong mang la: " << ntMax << "\n";
    } else {
        cout << "Mang khong co so nguyen to nao.\n";
    }

    // 7. Sap xep
    cout << "\n--- SAP XEP MANG ---\n";
    cArray arrTang = arr; // Tao ban sao de khong mat du lieu goc
    arrTang.SapXepTangDan();
    cout << "Mang sau khi sap xep TANG DAN: ";
    arrTang.XuatMang();

    cArray arrGiam = arr;
    arrGiam.SapXepGiamDan();
    cout << "Mang sau khi sap xep GIAM DAN: ";
    arrGiam.XuatMang();

    return 0;
}
