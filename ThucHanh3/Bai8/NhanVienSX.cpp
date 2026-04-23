#include "NhanVienSX.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

cNhanVienSX::cNhanVienSX() : maNV(""), hoTen(""), soSanPham(0), donGia(0.0) {}

cNgay cNhanVienSX::GetNgaySinh() const {
    return ngaySinh;
}

void cNhanVienSX::Nhap() {
    cout << "  Nhap ma nhan vien: ";
    getline(cin, maNV);

    cout << "  Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "  Nhap ngay sinh:\n";
    ngaySinh.Nhap();

    cout << "  Nhap so san pham: ";
    while (!(cin >> soSanPham) || soSanPham < 0) {
        cout << "So san pham phai >= 0. Nhap lai: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "  Nhap don gia 1 san pham: ";
    while (!(cin >> donGia) || donGia < 0) {
        cout << "Don gia phai >= 0. Nhap lai: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Xoa ki tu Enter bi ket lai trong bo dem sau khi nhap so
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void cNhanVienSX::Xuat() const {
    cout<< "- Ma NV: " << maNV <<'\t'
        << "Ten: " << hoTen  <<'\t'
        << "Ngay sinh: "; ngaySinh.Xuat();
    cout <<'\t' << "So SP: " << soSanPham <<'\t'
    << "Don gia: " << fixed << setprecision(0) << donGia <<'\t'
         << "Luong: " << TinhLuong() << "\n";
}

double cNhanVienSX::TinhLuong() const {
    return (double)soSanPham * donGia;
}
