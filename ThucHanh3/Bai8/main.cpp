#include <iostream>
#include <limits>
#include <iomanip>
#include "NhanVienSX.h"

using namespace std;

int NhapSoLuong() {
    int n;
    while (true) {
        cout << "Nhap so luong nhan vien san xuat: ";
        if (cin >> n && n > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return n;
        } else {
            cout << "Vui long nhap so nguyen lon hon 0!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main()
{
    cout << "=== CHUONG TRINH QUAN LY NHAN VIEN SAN XUAT ===\n\n";

    // 1. Nhap danh sach n nhan vien
    int n = NhapSoLuong();
    cNhanVienSX* danhSach = new cNhanVienSX[n];

    cout << "\n--- NHAP THONG TIN ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Nhan vien thu " << i + 1 << ":\n";
        danhSach[i].Nhap();
    }

    // 2. Xuat danh sach
    cout << "\n--- DANH SACH NHAN VIEN ---\n";
    for (int i = 0; i < n; i++) {
        danhSach[i].Xuat();
    }

    // 3. Cho biet nhan vien luong thap nhat
    cout << "\n--- NHAN VIEN CO LUONG THAP NHAT ---\n";
    int viTriMinLuong = 0;
    for (int i = 1; i < n; i++) {
        if (danhSach[i].TinhLuong() < danhSach[viTriMinLuong].TinhLuong()) {
            viTriMinLuong = i;
        }
    }
    danhSach[viTriMinLuong].Xuat();

    // 4. Tinh tong luong ma cong ty phai tra
    cout << "\n--- TONG LUONG CONG TY PHAI TRA ---\n";
    double tongLuong = 0;
    for (int i = 0; i < n; i++) {
        tongLuong += danhSach[i].TinhLuong();
    }
    cout << "Tong tien: " << fixed << setprecision(0) << tongLuong << " VND\n";

    // 5. Cho biet nhan vien co tuoi cao nhat (Sinh truoc)
    cout << "\n--- NHAN VIEN CO TUOI CAO NHAT ---\n";
    int viTriMaxTuoi = 0;
    for (int i = 1; i < n; i++) {
        if (danhSach[i].GetNgaySinh().LonTuoiHon(danhSach[viTriMaxTuoi].GetNgaySinh())) {
            viTriMaxTuoi = i;
        }
    }
    danhSach[viTriMaxTuoi].Xuat();

    // 6. Sap xep danh sach tang dan theo luong
    cout << "\n--- DANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG ---\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (danhSach[i].TinhLuong() > danhSach[j].TinhLuong()) {
                cNhanVienSX temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        danhSach[i].Xuat();
    }

    // Giai phong bo nho
    delete[] danhSach;
    return 0;
}
